/**
 * @file SerialMenuCmdLang.h
 *
 * @mainpage Serial Menu Command header file, languages
 *
 * @section description Description
 * This file contains dialog messages for user.
 *
 * @section circuit Circuit
 * This library is not attached to a device.
 *
 * @section libraries Libraries
 * None
 *
 * @section notes Notes
 * None at this time
 *
 * @section todo TODO
 * Translate and integrate in other languages
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
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @brief Language
 *        language default is ENGLISH. To change messages language, set the
 *        name of the desired language below, example :
 *        #define [ENGLISH or FRENCH]
 *        otherwise, create

 */

// Define Language, option -> replace by FRENCH
#define ENGLISH

// check if a language is selected
#if !(defined(ENGLISH) || defined(FRENCH))
// if no language defined then default language is ENGLISH
#define ENGLISH
#endif

#if defined(ENGLISH)
//                   0        1         2         3         4         5         6
// Size string char  "123456789012345678901234567890123456789012345678901234567890123"
// function member "begin"
#define TXT_fctMemberBegin_InvalidArguments "E1" // "structure, number of commands or text of prompt are invalid"
#define TXT_fctMemberBegin_OversizeCmdTxt "E2" // "Maximum number of characters is reached in a command text"
#define TXT_fctMemberBegin_OversizePrompt "E3" // "Maximum number of characters is reached in Command prompt"

// function member "ShowMenu"
#define TXT_fctMemberShowMenu_NoMenu "E4" // "No Menu in memory"
#define TXT_fctMemberShowMenu_PBInterf "E5" // "Interface mistake with library SerialSerialMenuCmd"

// function member "UserRequest"
#define TXT_fctMemberUserRequest_TooArgs "E6" // " -> too many arguments ! (one character only)"
#define TXT_fctMemberUserRequest_NoMatching "E7" // " -> No command code matching !"
#define TXT_fctMemberUserRequest_Cancellation "E8" // " -> cancellation !"

// function member "ConvStrToDTg"
#define TXT_fctMemberConvStrToDTg_TooChar "E9" // " -> too many characters ! (only 19 char) AAAA-MM-DDThh:mm:ss"
#define TXT_fctMemberConvStrToDTg_ErrHyphen "E10" // " -> Error of delimiter '-' in date"
#define TXT_fctMemberConvStrToDTg_ErrT "E11" // " -> Error of delimiter 'T' Between date and time"
#define TXT_fctMemberConvStrToDTg_ErrColon "E12" // " -> Error of delimiter ':' in time"

#define TXT_fctMemberConvStrToDTg_ErrYearFd "E13" // " -> Year field format error"
#define TXT_fctMemberConvStrToDTg_ErrMonthFd "E14" // " -> Month field format error"
#define TXT_fctMemberConvStrToDTg_ErrDayFd "E15" // " -> Day field format error"
#define TXT_fctMemberConvStrToDTg_ErrHourFd "E16" // " -> Hour field format error"
#define TXT_fctMemberConvStrToDTg_ErrMinuteFd "E17" // " -> Minute field format error"
#define TXT_fctMemberConvStrToDTg_ErrSecondFd "E18" // " -> Second field format error"

#define TXT_fctMemberConvStrToDTg_YearOutRange "E19" // " -> Year out of range, it must be between 1970 and 9999"
#define TXT_fctMemberConvStrToDTg_MonthOutRange "E20" // " -> Month out of range, it must be between 1 and 12"
#define TXT_fctMemberConvStrToDTg_DayOutRange "E21" // " -> Day out of range, it must be between 1 and 31"
#define TXT_fctMemberConvStrToDTg_HourOutRange "E22" // " -> Hour out of range, it must be between 0 and 23"
#define TXT_fctMemberConvStrToDTg_MinuteOutRange "E23" // " -> Minute out of range, it must be between 0 and 59"
#define TXT_fctMemberConvStrToDTg_SecondOutRange "E24" // " -> Second out of range, it must be between 0 and 59"

#define TXT_fctMemberConvStrToDTg_Month30day "E25" // " -> this month only has 30 days"
#define TXT_fctMemberConvStrToDTg_febLeap "E26" // " -> February only has 29 days in leap year"
#define TXT_fctMemberConvStrToDTg_febOutLeap "E27" // " -> February only has 28 days out of leap year"

#elif defined(FRENCH)
//                   0        1         2         3         4         5         6
// Size string char  "123456789012345678901234567890123456789012345678901234567890123"
// function member "begin"

#define TXT_fctMemberBegin_InvalidArguments "E1" // "La structure, le nombre de commande ou l'invite est invalide"
#define TXT_fctMemberBegin_OversizeCmdTxt "E2" // "Un text de commande dépasse le maximum de caractère possible"
#define TXT_fctMemberBegin_OversizePrompt "E3" // "le mamximum de caractère dans l'invite de commande est dépassé"

// function member "ShowMenu"
#define TXT_fctMemberShowMenu_NoMenu "E4" // "Aucun menu disponible"
#define TXT_fctMemberShowMenu_PBInterf "E5" // "Problème d'interface avec la bibliothèque SerialMenuCmd"

// function member "UserRequest"
#define TXT_fctMemberUserRequest_TooArgs "E6" // " -> trop d'arguments transmis (1 seul possible) !"
#define TXT_fctMemberUserRequest_NoMatching "E7" // " -> aucune commande ne correspond au code transmis !"
#define TXT_fctMemberUserRequest_Cancellation "E8" // " -> Annulation !"

// function member "ConvStrToDTg"
#define TXT_fctMemberConvStrToDTg_TooChar "E9" // " -> Trop de caractère (19 max.) AAAA-MM-DDThh:mm:ss"
#define TXT_fctMemberConvStrToDTg_ErrHyphen "E10" // " -> Erreur de délimiteur '-' dans la date"
#define TXT_fctMemberConvStrToDTg_ErrT "E11" // " -> Erreur de délimiteur 'T' entre la date et l'heuree"
#define TXT_fctMemberConvStrToDTg_ErrColon "E12" // " -> Erreur de délimiteur ':' dans l'heure"

#define TXT_fctMemberConvStrToDTg_ErrYearFd "E13" // " -> Erreur de format dans le champ année"
#define TXT_fctMemberConvStrToDTg_ErrMonthFd "E14" // " -> Erreur de format dans le champ mois"
#define TXT_fctMemberConvStrToDTg_ErrDayFd "E15" // " -> Erreur de format dans le champ jour"
#define TXT_fctMemberConvStrToDTg_ErrHourFd "E16" // " -> Erreur de format dans le champ heure"
#define TXT_fctMemberConvStrToDTg_ErrMinuteFd "E17" // " -> Erreur de format dans le champ  minute"
#define TXT_fctMemberConvStrToDTg_ErrSecondFd "E18" // " -> Erreur de format dans le champ seconde"

#define TXT_fctMemberConvStrToDTg_YearOutRange "E19" // " -> Année en dehors des limite, elle doit être comprise entre 1970 et 9999"
#define TXT_fctMemberConvStrToDTg_MonthOutRange "E20" // " -> Mois en dehors des limite, il doit être compris entre 1 et 12"
#define TXT_fctMemberConvStrToDTg_DayOutRange "E21" // " -> Jour en dehors des limite, il doit être compris entre 1 et 31"
#define TXT_fctMemberConvStrToDTg_HourOutRange "E22" // " -> Heure en dehors des limite, elle doit être compris entre 0 et 23"
#define TXT_fctMemberConvStrToDTg_MinuteOutRange "E23" // " -> Minute  en dehors des limite, elle doit être compris entre 0 et 59"
#define TXT_fctMemberConvStrToDTg_SecondOutRange "E24" // " -> Seconde  en dehors des limite, il doit être compris entre 0 et 59"

#define TXT_fctMemberConvStrToDTg_Month30day "E25" // " -> Ce mois comporte uniquement 30 jours"
#define TXT_fctMemberConvStrToDTg_febLeap "E26" // " -> Février comporte uniquement 29 jour en année bissextile"
#define TXT_fctMemberConvStrToDTg_febOutLeap "E27" // " -> Février comporte uniquement 28 jours en dehors des années bissextiles"

#endif