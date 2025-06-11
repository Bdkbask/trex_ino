# Mini T-Rex Game with ATTiny84

This project is a minimalist version of the classic Google Chrome T-Rex game, built using an ATTiny84 microcontroller. It features a small OLED screen and a single-button control. The entire setup runs on a coin cell battery and fits neatly on a breadboard.

## 🎮 Demo

![Gameplay Demo](assets/demo_trex.gif)

---

## 🔧 Components Used

- 🎮 **Microcontroller:** ATTiny84  
- 🖥️ **Display:** 0.91-inch I2C OLED screen (128x32 pixels)  
- 🔘 **Push Button** (x1)  
- 🔋 **Coin Cell Battery** (e.g., CR2032)  
- ⚙️ **Battery Holder**  
- 🔩 **Resistor:** 10 kΩ (for button pull-down)  
- 🧪 **Breadboard**  
- 🔌 **Jumper Wires**

---

## ⚙️ How It Works

- The screen displays the dinosaur and incoming obstacles.
- Pressing the button makes the dinosaur jump.
- The ATTiny84 uses its internal timer to manage gameplay and screen refresh.
- The setup is compact and battery-powered for full portability.
