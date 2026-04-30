/**
 * @file SerialMenuCmd.cpp
 *
 * @mainpage Serial Menu Command header file
 *
 * @section description Description
 * This file defines (implements) member functions of the class
 *
 *
 * @section circuit Circuit
 * This library is not attached to a device.
 *
 * @section libraries Libraries
 * the library itself and avr/pgmspace.h to store data in memory program space
 * when used in the visual studio Code environment, the arduino.h library has been added
 *
 * @section notes Notes
 * none at this time
 *
 * @section todo TODO
 * Test and adapt if necessary on other target (i.e. esp32)
 *
 * @version version Version
 * V1.0.0, May 05th 2021, initial release, Armand ROLLAND
 * V1.1.0, February 2022, added a function to get a date/time group from a string, Armand ROLLAND
 * V1.1.1, February 2022, adapt library to work with external terminals, Armand ROLLAND
 * V1.1.2, February 2022, Full compliance with terminals emulators and code restyling, Armand ROLLAND
 *
 * @section author Author
 * Armand ROLLAND -> armand.rolland71@gmail.com
 *
 * @copyright copyright MIT Licence
 * Copyright (c) 2021 Armand ROLLAND
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* Includes Files (libraries) ================================================================== */
#include <Arduino.h>
#include <SerialMenuCmd.h>
#include <SerialMenuCmdLang.h>

/* Macros ====================================================================================== */
#define ascii_CR 0x0D // Carrier Return
#define ascii_LF 0x0A // Line Feed
#define ascii_DLE 0x10 // Data link Escape
#define ascii_ESC 0x1B // Escape
#define ascii_BS 0x08 // Backspace


/* Implementation member functions ============================================================= */
SerialMenuCmd::SerialMenuCmd()
{
    /**
     * @brief default value is 0 or nullptr.
     *
     */
    mMenuCmds = nullptr;
    mPromptText = nullptr;
    mNbCmd = 0;
}


bool SerialMenuCmd::begin(stMenuCmd list[], uint8_t NbCmd, const char* acPrompt)
{
    /**
     * @brief  Before assigning the data, they are verified. In case of error the
     *         function displays a message and returns false
     *
     */
    uint8_t i;

    if ((NbCmd == 0) || (list == nullptr) || (acPrompt == nullptr)) {
        // Send to user : "structure, number of commands or text of prompt are
        // invalid"
        //SERIAL.println(F(TXT_fctMemberBegin_InvalidArguments));
        return false;
    }

    for (i = 0; i < NbCmd; i++) {
        if (strlen_P(list[i].itemTxt) > NB_MAX_CHAR_IN_TXT) {
            // Send to user : "one or more menu text exceeds the limit of the number
            // of characters allowed"
            //SERIAL.println(F(TXT_fctMemberBegin_OversizeCmdTxt));
            return false;
        }
    }

    if (strlen_P(acPrompt) > NB_MAX_CHAR_IN_TXT) {
        // Send to user : "text of prompt exceeds the limit of number of characters
        // allowed"
        //SERIAL.println(F(TXT_fctMemberBegin_OversizePrompt));
        return false;
    }

    mMenuCmds = list;
    mNbCmd = NbCmd;
    mPromptText = acPrompt;
    return true;
}


int8_t SerialMenuCmd::ExeCommand(uint8_t numItem)
{
    /**
     * @brief Execute function pointed by the structure. Before, checks if index
     * is valid.
     *
     *        Note : this function isn't blocking, but the function callback can
     * be.
     *
     */
    if ((numItem > mNbCmd) || (numItem == 0)) {
        return MENUCMD_ERROR_OVERRANGE_INDEX;
    }

    // Warning, For the user, the menu list ranges from 1 to n and for the system
    // it is from 0 to n-1
    mMenuCmds[numItem - 1].itemPtFunct();
    return true;
}


uint8_t SerialMenuCmd::searchCode(char car)
{
     /**
     * @brief compares key with code of each command du menu.
     *        Stops if matching ok or reaches the end of list.
     *        Return command numéro if matching otherwise 0.
     *        Warning, number command if index of the command in array + 1
     *        for memory, index array -> 0 to n-1 command
     */

    uint8_t i;
    bool fDetect = false;

    for (i = 0; i < mNbCmd; i++) {
        if (car == mMenuCmds[i].itemCode) {
            fDetect = true;
            break;
        }
    }

    if (fDetect == true) {
        return i + 1;
    } else {
        return 0;
    }
}


uint8_t SerialMenuCmd::getNbCmds(void)
{
    return mNbCmd;
}


void SerialMenuCmd::ShowMenu(void)
{
    /**
     * @brief for each menu command, the system displays the corresponding text
     *        however it is first checked that there are commands.
     *        regarding the length of character strings, they are checked at
     *        initialization time (see the "begin" member function)
     */

    uint8_t i;
    char sMenuN[NB_MAX_CHAR_IN_TXT];

    SERIAL.println("");
    if (mNbCmd == 0) {
        // Send to user : "No Menu in memory"
        //SERIAL.println(F(TXT_fctMemberShowMenu_NoMenu));

        // Send to user : "PB to interface with library SerialSerialMenuCmd")
        //SERIAL.println(F(TXT_fctMemberShowMenu_PBInterf));
        return;
    }

    for (i = 0; i < mNbCmd; i++) {
        /**
         * @brief strlcpy_P copy a maximum of NbMaxChar - 1 (last character is NULL
         * terminate) According to the IDE, the strlcpy_P function may need special
         * attention because the overriding function is only defined at compile
         * time.
         */
        if(char(mMenuCmds[i].itemCode)!= 'R' && char(mMenuCmds[i].itemCode) !='@'){ 
            strlcpy_P(sMenuN, mMenuCmds[i].itemTxt, NB_MAX_CHAR_IN_TXT);           
            SERIAL.print(char(mMenuCmds[i].itemCode));
            SERIAL.print(F(" : "));
            SERIAL.println(sMenuN);
        }
    }
}


void SerialMenuCmd::giveCmdPrompt(void)
{
    /**
     * @brief the command prompt consists of the text provided by the
     *        user (see, function member "begin") and the sign '>'
     *
     */
    char sMenuN[NB_MAX_CHAR_IN_TXT];

    SERIAL.println(F(""));
    /**
     * @brief strlcpy_P copy a maximum of NbMaxChar - 1 (last character is NULL
     * terminate) According to the IDE, the strlcpy_P function may need special
     * attention because the overriding function is only defined at compile time.
     */
    strlcpy_P(sMenuN, mPromptText, NB_MAX_CHAR_IN_TXT);
    SERIAL.print(sMenuN);
    SERIAL.print(F(">"));
}


uint8_t SerialMenuCmd::UserRequest(void)
{
     /**
     * @brief On each call, the function checks for the presence of a
     *        character in the serial stream. Each character is operated
     *        individually.
     *        Note : between 2 calls, the data is stored (variable with
     *        static prefix to avoid declaring a global variable).
     *
     *        Operating mode :
     *        a single keystroke (printable character) memorized, beyond that, t
     *        he user is warned that there are too many arguments (reset memory).
     *        For the other characters, only 'Carrier Return', 'Escape' and
     *        'Backspace' are managed.
     *
     *        Note : this function isn't blocking.
     */
    static char ValideCode;
    char kbEnter;
    uint8_t CodeCmd;

    CodeCmd = 0;
    if (SERIAL.available() > 0) {
        kbEnter = SERIAL.read();
        CodeCmd = this->searchCode(kbEnter);
    }        
    return CodeCmd;
}

