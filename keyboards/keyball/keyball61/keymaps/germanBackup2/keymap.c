/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_german.h"

// clang-format off
// Priority 1: a-z [öäüß] Enter Backspace Delete Super(LeftSuper) Tab Pos1=Home End Escape [Shift(LeftShift)] [Ctrl(LeftCtrl)] [Alt(LeftAlt)] [AltGr(LeftAlt)] [Fn] Mouse1 Mouse2 Mouse3 Scroll Mouse4(Back) Mouse5(Next)
// Priority 2: 0-9 () !?",.-+=*/\ ArrowKeys
// Priority 3: {} [] F1-12 ;:_ <>| %&#@€ Print Speaker(Mute Quieter Louder) MicMute Media(Previous Stop/Play Next) Display(Dimmer Brighter) Numpad?
// Priority 4: '´`~§$µ^°²³ Einfg CapsLock PageUp PageDown
// Do I need?: Calculator Lock DesktopView Pause Rollen NumLk
// Shortcuts Old: Undo(Ctrl+Z) Redo(Ctrl+Y) Copy(Ctrl+C) Paste(Ctrl+V) Cut(Ctrl+X) Duplicate(Ctrl+D) SelectAll(Ctrl+A)
// Shortcuts New: Undo(A)      Redo(S)      Copy(D)      Paste(F)      Cut(C)      Duplicate(V)      SelectAll()
// Shortcuts Old: Find(Ctrl+F) Save(Ctrl+S) Replace(Ctrl+R/Ctrl+H) Bookmarks(Ctrl+B)
// Shortcuts New: Find(G)      Save(X)      Replace(T)             Bookmarks(B)
// Shortcuts Old: CloseApp(Alt+F4) NewTab(Ctrl+T) CloseTab(Ctrl+W) Reload(F5/Ctrl+R)
// Shortcuts New: CloseApp(Q)      NewTab(E)      CloseTab(W)      Reload(R)
// Shortcuts Old: Rename(F2) DeleteWord(Ctrl+Backspace) DeleteWordForward(Ctrl+Delete) SwitchApp(Alt+Tab) SwitchTab(Ctrl+Tab)
// Shortcuts New: Rename(Z)  DeleteWord()               DeleteWordForward()            SwitchApp(Tab)     SwitchTab()

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//                                                                                 Basic Layer
  [0] = LAYOUT_universal(
    KC_PSCR      , DE_EXLM , DE_QUES , DE_DQUO , DE_SLSH      , DE_BSLS     ,                                DE_LPRN       , DE_RPRN , DE_LCBR , DE_RCBR , DE_LBRC , DE_RBRC      ,
    _______      , DE_Q    , DE_W    , DE_E    , DE_R         , DE_T        ,                                DE_Z          , DE_U    , DE_I    , DE_O    , DE_P    , DE_UDIA      ,
    KC_TAB       , DE_A    , DE_S    , DE_D    , DE_F         , DE_G        ,                                DE_H          , DE_J    , DE_K    , DE_L    , DE_ODIA , DE_ADIA      ,
    MO(1)        , DE_Y    , DE_X    , DE_C    , DE_V         , DE_B        , _______     ,    TG(2)       , DE_N          , DE_M    , DE_COMM , DE_DOT  , DE_MINS , DE_SS  n      ,
    LT(3,_______), _______ , KC_LGUI , KC_LALT , CTL_T(KC_ESC), LT(2,KC_SPC), LT(5,KC_ENT),    LT(4,KC_DEL), SFT_T(KC_BSPC), _______ , _______ , _______ , _______ , LT(3,_______)
  ),
//                              LEFT USA ANSI                                                                                         LEFT USA ANSI
//  Escape           , 1 and !  , 2 and @ , 3 and # , 4 and $              , 5 and %         ,
//  Delete           , Q        , W       , E       , R                    , T               ,
//  Tab              , A        , S       , D       , F                    , G               ,
//  Momentary Layer 1, Z        , X       , C       , V                    , B               , ] and }              ,
//  _______          , Left Ctrl, Left Alt, Super   , Language 2 or Layer 1, Space or Layer 2, Language 1 or Layer 3,
//                              RIGHT USA ANSI                                                                                        RIGHT USA ANSI
//                                                                                      6 and ^         , 7 and &              , 8 and *    , 9 and ( , 0 and )  , - and _        ,
//                                                                                      Y               , U                    , I          , O       , P        , International 3,
//                                                                                      H               , J                    , K          , L       , ; and :  , /              ,
//                                                                      Non-US # and ~, N               , M                    , , and <    , . and > , / and ?  , Right Shift    ,
//                                                                      Backspace     , Enter or Layer 2, Language 2 or Layer 1, Right Super, _______ , Right Alt, Print          ,
//
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  Print           , !       , ?       , "       , /             , \              ,                                       (                 , )       , {       , }       , [       , ]       ,
//  _______         , q       , w       , e       , r             , t              ,                                       z                 , u       , i       , o       , p       , ü       ,
//  Tab             , a       , s       , d       , f             , g              ,                                       h                 , j       , k       , l       , ö       , ä       ,
//  Momentary Layer1, y       , x       , c       , v             , b              , _______ ,           _______         , n                 , m       , ,       , .       , -       , ß       ,
//  Layer3          , _______ , Super   , Alt     , Ctrl or Escape, Layer2 or Space, Layer5 or Enter,    Layer4 or Delete, Shift or Backspace, _______ , _______ , _______ , _______ , Layer3  ,
// Pos1 End


//                                                                                   Numpad Layer
  [1] = LAYOUT_universal(
    _______  , _______ , _______ , DE_QUOT , _______ , _______ ,                                                     _______ , _______ , _______ , _______ , _______   , _______   ,
    _______  , S(DE_Q) , S(DE_W) , S(DE_E) , S(DE_R) , S(DE_T) ,                                                     S(DE_Z) , S(DE_U) , S(DE_I) , S(DE_O) , S(DE_P)   , S(DE_UDIA),
    S(KC_TAB), S(DE_A) , S(DE_S) , S(DE_D) , S(DE_F) , S(DE_G) ,                                                     S(DE_H) , S(DE_J) , S(DE_K) , S(DE_L) , S(DE_ODIA), S(DE_ADIA),
    _______  , S(DE_Y) , S(DE_X) , S(DE_C) , S(DE_V) , S(DE_B) , _______ ,                                 _______ , S(DE_N) , S(DE_M) , DE_SCLN , DE_COLN , DE_UNDS   , DE_SS     ,
    _______  , _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______   , _______
  ),
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______ , _______ , _______ , '       , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , Q       , W       , E       , R       , T       ,                                                         Z       , U       , I       , O       , P       , Ü       ,
//  _______ , A       , S       , D       , F       , G       ,                                                         H       , J       , K       , L       , Ö       , A       ,
//  _______ , Y       , X       , C       , V       , B       , _______ ,                                     _______ , N       , M       , ;       , :       , _       , ß       ,
//  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,


//                                                                               Control/Shortcut/Mouse Layer
  [2] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                    _______ , KC_HOME , KC_UP   , KC_END       , _______ , _______ ,
    _______ , A(KC_F4), C(DE_W) , C(DE_T) , C(DE_R) , C(DE_H) ,                                                    _______ , KC_LEFT , KC_DOWN , KC_RGHT      , _______ , _______ ,
    KC_TAB  , C(DE_Z) , C(DE_Y) , C(DE_C) , C(DE_V) , C(DE_F) ,                                                    _______ , KC_BTN1 , KC_BTN2 , LT(5,KC_BTN3), _______ , _______ ,
    _______ , KC_F2   , C(DE_S) , C(DE_X) , C(DE_D) , C(DE_B) , _______ ,                                _______ , _______ , KC_BTN4 , KC_BTN5 , _______      , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                _______ , _______ , _______ , _______ , _______      , _______ , _______
  ),
//                              LEFT USA ANSI                                                                                         RIGHT USA ANSI
//  Free Scroll    , F1      , F2      , F3      , F4      , F5      ,                                                 F6       , F7      , F8      , F9      , F10     , F11     ,
//  Vertical Snap  , _______ , 7       , 8       , 9       , _______ ,                                                 _______  , Left    , Up      , Right   , _______ , F12     ,
//  Horizontal Snap, _______ , 4       , 5       , 6       , :       ,                                                 Page Up  , Mouse 1 , Down    , Mouse 2 , Mouse 3 , _______ ,
//  _______        , _______ , 1       , 2       , 3       , _       , *       ,                            (        , Page Down, _______ , _______ , _______ , _______ , _______ ,
//  _______        , _______ , 0       , .       , _______ , _______ , _______ ,                            Delete   , _______  , _______ , _______ , _______ , _______ , _______ ,
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______  , _______ , _______ , _______ , _______  , _______ ,                                                       _______ , Pos 1   , Up      , End     , _______ , _______ ,
//  _______  , CloseApp, CloseTab, NewTab  , Reload   , Replace ,                                                       _______ , Left    , Down    , Right   , _______ , _______ ,
//  SwitchApp, Undo    , Redo    , Copy    , Paste    , Find    ,                                                       _______ , Mouse 1 , Mouse 2 , Mouse 3 , _______ , _______ ,
//  _______  , Rename  , Save    , Cut     , Duplicate, Bookmark, _______ ,                                   _______ , _______ , Mouse 4 , Mouse 5 , _______ , _______ , _______ ,
//  _______  , _______ , _______ , _______ , _______  , _______ , _______ ,                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ ,


//                                                                               ? Layer
  [3] = LAYOUT_universal(
    QK_BOOT , AML_TO  , AML_I50 , AML_D50 , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , QK_BOOT ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         CPI_D1K , CPI_D100, CPI_I100, CPI_I1K , KBC_SAVE, KBC_RST ,
    _______ , _______ , SCRL_DVD, SCRL_DVI, SCRL_MO , SCRL_TO , EE_CLR  ,                                     EE_CLR  , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ , _______ ,
    QK_BOOT , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ ,                                     _______ , KC_BSPC , _______ , _______ , _______ , _______ , QK_BOOT
  ),
//                              LEFT USA ANSI                                                                                         LEFT USA ANSI
//  RGB?      , AML?    , AML?                   , AML?                   , _______         , _______           ,
//  RGB?      , RGB?    , RGB?                   , RGB?                   , _______         , _______           ,
//  RGB?      , RGB?    , RGB?                   , RGB?                   , _______         , _______           ,
//  _______   , _______ , Decrease Scroll Divider, Increase Scroll Divider, Hold Scroll Mode, Toggle Scroll Mode, Clear EEPROM,
//  Bootloader, _______ , Left                   , Down                   , Up              , Right             , _______     ,
//                              RIGHT USA ANSI                                                                                       RIGHT USA ANSI
//                                                    RGB Static Mode   , RGB Breathing Mode      , RGB Rainbow Mode, RGB Swirl Mode   , RGB Snake Mode     , RGB Knight Mode     ,
//                                                    RGB Christmas Mode, RGB Static Gradient Mode, RGB Test Mode   , RGB Twinkle Mode , _______            , _______             ,
//                                                    Decrease 1000 CPI , Decrease 100 CPI        , Increase 100 CPI, Increase 1000 CPI, Save Keyball Config, Reset Keyball Config,
//                                      Clear EEPROM, Home=Pos1         , Page Down               , Page Up         , End              , _______            , _______             ,
//                                      _______     , Backspace         , _______                 , _______         , _______          , _______            , Bootloader          ,
//
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,


//                                                                               Number Layer
  [4] = LAYOUT_universal(
    _______ , _______ , DE_DLR  , DE_EURO , DE_PERC , DE_SLSH ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , DE_COLN , DE_7    , DE_8    , DE_9    , DE_ASTR ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , DE_COMM , DE_4    , DE_5    , DE_6    , DE_EQL  ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , DE_DOT  , DE_1    , DE_2    , DE_3    , DE_PLUS , DE_MINS ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , DE_0    , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
//                              LEFT USA ANSI                                                                                         LEFT USA ANSI
//  RGB?      , AML?    , AML?                   , AML?                   , _______         , _______           ,
//  RGB?      , RGB?    , RGB?                   , RGB?                   , _______         , _______           ,
//  RGB?      , RGB?    , RGB?                   , RGB?                   , _______         , _______           ,
//  _______   , _______ , Decrease Scroll Divider, Increase Scroll Divider, Hold Scroll Mode, Toggle Scroll Mode, Clear EEPROM,
//  Bootloader, _______ , Left                   , Down                   , Up              , Right             , _______     ,
//                              RIGHT USA ANSI                                                                                       RIGHT USA ANSI
//                                                    RGB Static Mode   , RGB Breathing Mode      , RGB Rainbow Mode, RGB Swirl Mode   , RGB Snake Mode     , RGB Knight Mode     ,
//                                                    RGB Christmas Mode, RGB Static Gradient Mode, RGB Test Mode   , RGB Twinkle Mode , _______            , _______             ,
//                                                    Decrease 1000 CPI , Decrease 100 CPI        , Increase 100 CPI, Increase 1000 CPI, Save Keyball Config, Reset Keyball Config,
//                                      Clear EEPROM, Home=Pos1         , Page Down               , Page Up         , End              , _______            , _______             ,
//                                      _______     , Backspace         , _______                 , _______         , _______          , _______            , Bootloader          ,
//
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______ , _______ , $       , €       , %       , /       ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , :       , 7       , 8       , 9       , *       ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , ,       , 4       , 5       , 6       , =       ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , .       , 1       , 2       , 3       , +       , -       ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , 0 , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 5
    keyball_set_scroll_mode(get_highest_layer(state) == 5);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

