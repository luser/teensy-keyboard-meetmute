/*
 * To the extent possible under law, the author(s) have dedicated all copyright and related and
 * neighboring rights to this software to the public domain worldwide. This software is
 * distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along with this software.
 * If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <Bounce.h>

Bounce button0 = Bounce(0, 10);  // 10 ms debounce time

void setup() {
  pinMode(0, INPUT_PULLUP);
}

void loop() {
  button0.update();

  if (button0.fallingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_SHIFT | MODIFIERKEY_GUI);
    Keyboard.set_key1(KEY_7);
    Keyboard.send_now();
    delay(10);
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
}
