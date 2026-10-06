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
// Priority 2: 0-9 () !?",.-+=*/\ ArrowKeys SideScroll(Shift on Layer 5)
// Priority 3: {} [] F1-12 ;:_ <>| %&#@€ Print Speaker(Mute Quieter Louder) MicMute Media(Previous Stop/Play Next) Display(Dimmer Brighter)
// Priority 4: '´`~§$µ^°²³ Einfg CapsLock PageUp PageDown
// Do I need?: Calculator Lock DesktopView Pause Rollen NumLk
// Shortcuts Old: Undo(Ctrl+Z) Redo(Ctrl+Y) Copy(Ctrl+C) Paste(Ctrl+V) Cut(Ctrl+X) Duplicate(Ctrl+D) SelectAll(Ctrl+A)
// Shortcuts New: Undo(A)      Redo(S)      Copy(D)      Paste(F)      Cut(C)      Duplicate(V)      SelectAll()
// Shortcuts Old: Find(Ctrl+F) Save(Ctrl+S) Replace(Ctrl+R/Ctrl+H) Bookmarks(Ctrl+B)
// Shortcuts New: Find(G)      Save(X)      Replace(T)             Bookmarks(B)
// Shortcuts Old: CloseApp(Alt+F4) NewTab(Ctrl+T) CloseTab(Ctrl+W) Reload(F5/Ctrl+R) BrowserConsole(F12)
// Shortcuts New: CloseApp(Q)      NewTab(E)      CloseTab(W)      Reload(R)         BrowserConsole()
// Shortcuts Old: Rename(F2) DeleteWord(Ctrl+Backspace) DeleteWordForward(Ctrl+Delete) SwitchApp(Alt+Tab) SwitchTab(Ctrl+Tab)
// Shortcuts New: Rename(Z)  DeleteWord()               DeleteWordForward()            SwitchApp(Alt+Tab) SwitchTab(Ctrl+Tab)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//                                                                                 Base Layer
  [0] = LAYOUT_universal(
    KC_PSCR      , DE_EXLM , DE_QUES , DE_DQUO , DE_SLSH      , DE_BSLS     ,                              DE_LPRN       , DE_RPRN , DE_LCBR , DE_RCBR   , DE_LBRC , DE_RBRC      ,
    DE_AT        , DE_Q    , DE_W    , DE_E    , DE_R         , DE_T        ,                              DE_Z          , DE_U    , DE_I    , DE_O      , DE_P    , DE_UDIA      ,
    KC_TAB       , DE_A    , DE_S    , DE_D    , DE_F         , DE_G        ,                              DE_H          , DE_J    , DE_K    , LT(6,DE_L), DE_ODIA , DE_ADIA      ,
    KC_LSFT      , DE_Y    , DE_X    , DE_C    , DE_V         , DE_B        , DE_QUOT     ,  TG(3)       , DE_N          , DE_M    , DE_COMM , DE_DOT    , DE_MINS , DE_SS        ,
    LT(5,_______), DE_AMPR , KC_LGUI , KC_LALT , CTL_T(KC_ESC), LT(3,KC_SPC), KC_ENT      ,  LT(4,KC_BSPC), SFT_T(KC_DEL), _______ , _______ , _______   , TG(2)   , LT(5,_______)
  ),
//                              LEFT GERMAN                                                                                           LEFT GERMAN
//  Print   , !       , ?       , "       , /             , \              ,
//  @       , q       , w       , e       , r             , t              ,
//  Tab     , a       , s       , d       , f             , g              ,
//  Shift   , y       , x       , c       , v             , b              , '              ,
//  Layer3  , &       , Super   , Alt     , Ctrl or Escape, Layer2 or Space, Layer5 or Enter,
//                              RIGHT GERMAN                                                                                          RIGHT GERMAN
//                                                                                                        (              , )       , {       , }          , [           , ]       ,
//                                                                                                        z              , u       , i       , o          , p           , ü       ,
//                                                                                                        h              , j       , k       , Layer6 or l, ö           , ä       ,
//                                                                                   ToggleLayer2       , n              , m       , ,       , .          , -           , ß       ,
//                                                                                   Layer4 or Backspace, Shift or Delete, _______ , _______ , _______    , ToggleLayer5, Layer3  ,


//                                                                                   Blender Layer
  [1] = LAYOUT_universal(
    KC_ESC  , DE_1    , DE_1    , DE_2    , DE_3    , DE_4    ,                                                         _______ , KC_HOME , KC_UP   , KC_END  , _______ , _______ ,
    KC_TAB  , DE_M    , DE_Q    , DE_W    , DE_E    , DE_R    ,                                                         _______ , KC_LEFT , KC_DOWN , KC_RGHT , DE_L    , _______ ,
    DE_I    , KC_LSFT , DE_A    , DE_S    , DE_D    , DE_F    ,                                                         _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ ,
    DE_P    , KC_LCTL , DE_Y    , DE_X    , DE_C    , DE_V    , DE_B    ,                                     _______ , _______ , KC_BTN4 , KC_BTN5 , _______ , _______ , _______ ,
    DE_H    , DE_U    , _______ , KC_LALT , KC_LCTL , KC_SPC  , KC_ENT  ,                                     _______ , _______ , _______ , _______ , _______ , TG(1)   , _______
  ),
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  Escape  , 1       , 1       , 2       , 3       , 4       ,                                                     _______ , Pos 1   , Up      , End     , _______     , _______ ,
//  Tab     , m       , q       , w       , e       , r       ,                                                     _______ , Left    , Down    , Right   , l           , _______ ,
//  i       , Shift   , a       , s       , d       , f       ,                                                     _______ , Mouse 1 , Mouse 2 , Mouse 3 , _______     , _______ ,
//  p       , Ctrl    , y       , x       , c       , v       , b       ,                                 _______ , _______ , Mouse 4 , Mouse 5 , _______ , _______     , _______ ,
//  h       , u       , _______ , Alt     , Ctrl    , Space   , Enter   ,                                 _______ , Shift   , _______ , _______ , _______ , ToggleLayer5, _______ ,


//                                                                                   Gaming Layer
  [2] = LAYOUT_universal(
    KC_ESC  , DE_1    , DE_1    , DE_2    , DE_3    , DE_4    ,                                                         _______ , KC_HOME , KC_UP   , KC_END  , _______ , _______ ,
    KC_TAB  , DE_M    , DE_Q    , DE_W    , DE_E    , DE_R    ,                                                         _______ , KC_LEFT , KC_DOWN , KC_RGHT , DE_L    , _______ ,
    DE_I    , KC_LSFT , DE_A    , DE_S    , DE_D    , DE_F    ,                                                         _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ ,
    DE_P    , KC_LCTL , DE_Y    , DE_X    , DE_C    , DE_V    , DE_B    ,                                     _______ , _______ , KC_BTN4 , KC_BTN5 , _______ , _______ , _______ ,
    DE_H    , DE_U    , _______ , KC_LALT , KC_LCTL , KC_SPC  , KC_ENT  ,                                     _______ , _______ , _______ , _______ , _______ , TG(2)   , _______
  ),
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  Escape  , 1       , 1       , 2       , 3       , 4       ,                                                     _______ , Pos 1   , Up      , End     , _______     , _______ ,
//  Tab     , m       , q       , w       , e       , r       ,                                                     _______ , Left    , Down    , Right   , l           , _______ ,
//  i       , Shift   , a       , s       , d       , f       ,                                                     _______ , Mouse 1 , Mouse 2 , Mouse 3 , _______     , _______ ,
//  p       , Ctrl    , y       , x       , c       , v       , b       ,                                 _______ , _______ , Mouse 4 , Mouse 5 , _______ , _______     , _______ ,
//  h       , u       , _______ , Alt     , Ctrl    , Space   , Enter   ,                                 _______ , Shift   , _______ , _______ , _______ , ToggleLayer5, _______ ,


//                                                                        Control/Shortcut/Mouse Layer
  [3] = LAYOUT_universal(
    S(KC_F10), _______ , KC_F12  , KC_F4   , C(S(DE_N)), LCA(DE_F),                                       _______      , KC_HOME , KC_UP   , KC_END       , G(KC_UP)  , G(KC_DOWN),
    KC_F9    , A(KC_F4), C(DE_W) , C(DE_T) , C(DE_R)   , C(DE_H)  ,                                       A(S(KC_BTN1)), KC_LEFT , KC_DOWN , KC_RGHT      , G(KC_LEFT), G(KC_RGHT),
    KC_TAB   , C(DE_Z) , C(DE_Y) , C(DE_C) , C(DE_V)   , C(DE_F)  ,                                       C(KC_BTN1)   , KC_BTN1 , KC_BTN2 , LT(6,KC_BTN3), C(S(DE_L)), LSA(DE_A) ,
    C(DE_A)  , KC_F2   , C(DE_S) , C(DE_X) , C(DE_D)   , C(DE_B)  , _______ ,                   TG(3)   , _______      , KC_BTN4 , KC_BTN5 , _______      , _______   , _______   ,
    _______  , _______ , _______ , _______ , _______   , _______  , _______ ,                   _______ , _______      , _______ , _______ , _______      , _______   , _______
  ),
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  Run Code , _______ , Console , Open    , New Folder, FindInFiles,                                     _______     , Pos 1   , Up      , End               , WinUp   , WinDown ,
//  Debug    , CloseApp, CloseTab, NewTab  , Reload    , Replace    ,                                     MultiSelect , Left    , Down    , Right             , WinLeft , WinRight,
//  SwitchApp, Undo    , Redo    , Copy    , Paste     , Find       ,                                     ControlClick, Mouse 1 , Mouse 2 , Layer6 or Mouse 3 , FillForm, DarkWebs,
//  SelectAll, Rename  , Save    , Cut     , Duplicate , Bookmark   , _______ ,                 _______ , _______     , Mouse 4 , Mouse 5 , _______           , _______ , _______ ,
//  _______  , _______ , _______ , _______ , _______   , _______    , _______ ,                 _______ , _______     , _______ , _______ , _______           , _______ , _______ ,


//                                                                      Number/Special Layer
  [4] = LAYOUT_universal(
    DE_ACUT , DE_HASH , DE_DLR  , DE_EURO , DE_PERC , DE_SLSH ,                                     DE_LABK , DE_RABK         , DE_PIPE           , DE_AMPR   , _______ , KC_PGUP ,
    DE_GRV  , DE_COLN , DE_7    , DE_8    , DE_9    , DE_ASTR ,                                     _______ , KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN, KC_MUTE   , _______ , KC_PGDN ,
    DE_TILD , DE_COMM , DE_4    , DE_5    , DE_6    , DE_EQL  ,                                     _______ , KC_KB_VOLUME_UP , KC_KB_VOLUME_DOWN , KC_KB_MUTE, _______ , KC_CAPS ,
    DE_SECT , DE_DOT  , DE_1    , DE_2    , DE_3    , DE_PLUS , DE_MINS ,                 _______ , _______ , KC_MPLY         , KC_MNXT           , KC_MPRV   , _______ , KC_INS  ,
    DE_MICR , DE_SUP2 , DE_SUP3 , DE_0    , _______ , _______ , _______ ,                 _______ , _______ , _______         , _______           , _______   , _______ , KC_PAUS
  ),
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  ´       , #       , $       , €       , %       , /       ,                                       <       , >              , |             , &            , _______ , PageUp  ,
//  `       , :       , 7       , 8       , 9       , *       ,                                       _______ , DisplayBrighter, DisplayDimmer , MicMute      , _______ , PageDown,
//  ~       , ,       , 4       , 5       , 6       , =       ,                                       _______ , SpeakerLouder  , SpeakerQuieter, SpeakerMute  , _______ , CapsLock,
//  §       , .       , 1       , 2       , 3       , +       , -       ,                   _______ , _______ , MediaStop/Play , MediaNext     , MediaPrevious, _______ , Einfg   ,
//  µ       , ²       , ³       , 0       , _______ , _______ , _______ ,                   _______ , _______ , _______        , _______       , _______      , _______ , Pause   ,


//                                                                                  Config Layer
  [5] = LAYOUT_universal(
    QK_BOOT , AML_TO  , AML_I50 , AML_D50 , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , QK_BOOT ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    KBC_RST , KBC_SAVE, CPI_D100, CPI_I100, CPI_D1K , CPI_I1K ,                                                         CPI_D1K , CPI_D100, CPI_I100, CPI_I1K , KBC_SAVE, KBC_RST ,
    _______ , _______ , SCRL_DVD, SCRL_DVI, SCRL_MO , SCRL_TO , EE_CLR  ,                                     EE_CLR  , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ , _______ ,
    QK_BOOT , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ ,                                     _______ , KC_BSPC , _______ , _______ , _______ , TG(1)   , QK_BOOT
  ),
//  AML = Automatic Mouse Layer, CPI = Trackball Speed
//                              LEFT GERMAN                                                                                           RIGHT GERMAN
//  Bootloader, ToggleAML, +50AMLtimeout, -50AMLtimeout, _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______   , Bootloader ,
//  _______   , _______  , _______      , _______      , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______   , _______    ,
//  _______   , _______  , _______      , _______      , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______   , _______    ,
//  _______   , _______  , _______      , _______      , _______ , _______ , ClearMemory,             ClearMemory, -1000CPI, -100CPI , +100CPI , +1000CPI, SaveConfig, ResetConfig,
//  Bootloader, _______  , Left         , Down         , Up      , Right   , _______    ,             _______    , _______ , _______ , _______ , _______ , _______   , Bootloader ,


//                                                                                    Scroll Layer
  [6] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                                         _______ , _______ , KC_LSFT , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______ , _______ , _______ , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 6
    keyball_set_scroll_mode(get_highest_layer(state) == 6);
    return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
