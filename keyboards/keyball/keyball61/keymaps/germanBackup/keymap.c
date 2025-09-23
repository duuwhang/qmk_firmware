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
// Shortcuts Old: Undo(Ctrl+Z) Redo(Ctrl+Y) Copy(Ctrl+C) Paste(Ctrl+V) Cut(Ctrl+X) Duplicate(Ctrl+D)
// Shortcuts New: Undo(A)      Redo(S)      Copy(D)      Paste(F)      Cut(C)      Duplicate(V)
// Shortcuts Old: Find(Ctrl+F) Save(Ctrl+S) Replace(Ctrl+R/Ctrl+H) Bookmarks(Ctrl+B)
// Shortcuts New: Find(G)      Save(X)      Replace(T)             Bookmarks(B)
// Shortcuts Old: CloseApp(Alt+F4) NewTab(Ctrl+T) CloseTab(Ctrl+W) Reload(F5/Ctrl+R)
// Shortcuts New: CloseApp(Q)      NewTab(E)      CloseTab(W)      Reload(R)
// Shortcuts Old: Rename(F2)
// Shortcuts New: Rename()

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC  , DE_1    , DE_2    , DE_3    , DE_4        , DE_5        ,                                            DE_6         , DE_7    , DE_8    , DE_9    , DE_0    , DE_SS   ,
    KC_DEL  , DE_Q    , DE_W    , DE_E    , DE_R        , DE_T        ,                                            DE_Z         , DE_U    , DE_I    , DE_O    , DE_P    , KC_INT3 ,
    KC_TAB  , DE_A    , DE_S    , DE_D    , DE_F        , DE_G        ,                                            DE_H         , DE_J    , DE_K    , DE_L    , DE_ODIA , DE_SLSH ,
    MO(1)   , DE_Y    , DE_X    , DE_C    , DE_V        , DE_B        , DE_PLUS     ,                DE_HASH     , DE_N         , DE_M    , DE_COMM , DE_DOT  , DE_MINS , KC_RSFT ,
    _______ , KC_LCTL , KC_LALT , KC_LGUI , LT(1,KC_ESC), LT(2,KC_SPC), LT(3,KC_ENT),                LT(3,KC_DEL), LT(2,KC_BSPC), _______ , _______ , _______ , KC_RALT , KC_PSCR
  ),
//                                                                                 Basic Layer
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
//  _______ , _______ , _______ , _______ , _______       , _______ ,                                        _______            , _______ , _______ , _______ , _______ , _______ ,
//  _______ , q       , w       , e       , r             , t       ,                                        z                  , u       , i       , o       , p       , ü?      ,
//  Tab     , a       , s       , d       , f             , g       ,                                        h                  , j       , k       , l       , ö?      , ä?      ,
//  _______ , y       , x       , c       , v             , b       , _______ ,                   _______  , n                  , m       , _______ , _______ , _______ , ß?      ,
//  _______ , _______ , _______ , Super   ,  or Escape, Ctrl or Space, or Enter,                  or Delete, Layer1 or Backspace, _______ , _______ , _______ , _______ , _______ ,
// Pos1 End
  [1] = LAYOUT_universal(
    S(KC_ESC), DE_EXLM   , DE_UDIA   , DE_SECT   , DE_DLR  , DE_PERC ,                                            DE_ACUT , DE_AMPR , S(DE_ADIA), DE_LPRN , DE_RPRN   , S(KC_INT1),
    S(KC_DEL), S(DE_Q)   , S(DE_W)   , S(DE_E)   , S(DE_R) , S(DE_T) ,                                            S(DE_Z) , S(DE_U) , S(DE_I)   , S(DE_O) , S(DE_P)   , S(KC_INT3),
    S(KC_TAB), S(DE_A)   , S(DE_S)   , S(DE_D)   , S(DE_F) , S(DE_G) ,                                            S(DE_H) , S(DE_J) , S(DE_K)   , S(DE_L) , DE_ADIA   , DE_DQUO   ,
    _______  , S(DE_Y)   , S(DE_X)   , S(DE_C)   , S(DE_V) , S(DE_B) , DE_ASTR ,                        DE_QUOT , S(DE_N) , S(DE_M) , DE_SCLN   , DE_COLN , DE_UNDS   , S(KC_RSFT),
    _______  , S(KC_LCTL), S(KC_LALT), S(KC_LGUI), _______ , _______ , _______ ,                        _______ , _______ , _______ , S(KC_RGUI), _______ , S(KC_RALT), _______
  ),
//                                                                                   Shift Layer
//                              LEFT USA ANSI                                                                                         RIGHT USA ANSI
//  Escape  , !        , [        , #         , $       , %       ,                                          =       , ^       , "          , *       , (        , International 1,
//  Delete  , Q        , W        , E         , R       , T       ,                                          Z       , U       , I          , O       , P        , International 3,
//  Tab     , A        , S        , D         , F       , G       ,                                          H       , J       , K          , L       , '        , @              ,
//  _______ , Z        , X        , C         , V       , B       , }       ,                      ~       , N       , M       , <          , >       , ?        , Right Shift    ,
//  _______ , Left Ctrl, Left Alt , Left Super, _______ , _______ , _______ ,                      _______ , _______ , _______ , Right Super, _______ , Right Alt, _______        ,
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , Q       , W       , E       , R       , T       ,                                                         Z       , U       , I       , O       , P       , Ü?      ,
//  _______ , A       , S       , D       , F       , G       ,                                                         H       , J       , K       , L       , Ö?      , _______ ,
//  _______ , Y       , X       , C       , V       , B       , _______ ,                                     _______ , N       , M       , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,

  [2] = LAYOUT_universal(
    SSNP_FRE, KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5     ,                                                       KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    SSNP_VRT, _______ , DE_7    , DE_8    , DE_9    , _______   ,                                                       _______ , KC_LEFT , KC_UP   , KC_RGHT , _______ , KC_F12  ,
    SSNP_HOR, _______ , DE_4    , DE_5    , DE_6    , S(DE_ODIA),                                                       KC_PGUP , KC_BTN1 , KC_DOWN , KC_BTN2 , KC_BTN3 , _______ ,
    _______ , _______ , DE_1    , DE_2    , DE_3    , DE_QUES   , DE_LPRN ,                                  DE_RPRN  , KC_PGDN , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , DE_0    , DE_DOT  , _______ , _______   , _______ ,                                  KC_DEL   , _______ , _______ , _______ , _______ , _______ , _______
  ),
//                                                                               Control/Shortcut/Mouse Layer
//                              LEFT USA ANSI                                                                                         RIGHT USA ANSI
//  Free Scroll    , F1      , F2      , F3      , F4      , F5      ,                                                 F6       , F7      , F8      , F9      , F10     , F11     ,
//  Vertical Snap  , _______ , 7       , 8       , 9       , _______ ,                                                 _______  , Left    , Up      , Right   , _______ , F12     ,
//  Horizontal Snap, _______ , 4       , 5       , 6       , :       ,                                                 Page Up  , Mouse 1 , Down    , Mouse 2 , Mouse 3 , _______ ,
//  _______        , _______ , 1       , 2       , 3       , _       , *       ,                            (        , Page Down, _______ , _______ , _______ , _______ , _______ ,
//  _______        , _______ , 0       , .       , _______ , _______ , _______ ,                            Delete   , _______  , _______ , _______ , _______ , _______ , _______ ,
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  _______ , _______ , _______ , _______ , _______  , _______ ,                                                         _______ , Pos 1   , Up      , End     , _______ , _______ ,
//  _______ , CloseApp, CloseTab, NewTab  , Reload   , Replace ,                                                         _______ , Left    , Down    , Right   , _______ , _______ ,
//  _______ , Undo    , Redo    , Copy    , Paste    , Find    ,                                                         _______ , Mouse 1 , Mouse 2 , Mouse 3 , _______ , _______ ,
//  _______ , _______ , Save    , Cut     , Duplicate, Bookmark, _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//  _______ , _______ , _______ , _______ , _______  , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  [3] = LAYOUT_universal(
    RGB_TOG , AML_TO  , AML_I50 , AML_D50 , _______ , _______ ,                                                         RGB_M_P , RGB_M_B , RGB_M_R , RGB_M_SW, RGB_M_SN, RGB_M_K ,
    RGB_MOD , RGB_HUI , RGB_SAI , RGB_VAI , _______ , _______ ,                                                         RGB_M_X , RGB_M_G , RGB_M_T , RGB_M_TW, _______ , _______ ,
    RGB_RMOD, RGB_HUD , RGB_SAD , RGB_VAD , _______ , _______ ,                                                         CPI_D1K , CPI_D100, CPI_I100, CPI_I1K , KBC_SAVE, KBC_RST ,
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
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
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

