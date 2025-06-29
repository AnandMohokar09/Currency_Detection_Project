# Currency Detection for Visually Impaired

A hardware project using TCS3200 color sensor and DFPlayer Mini for currency detection.

This is a hardware project designed to help visually impaired individuals identify Indian currency notes by detecting their color combination and announcing the denomination through an audio output.

The system uses a **TCS3200 Color Sensor** to read the color values of currency notes and a **DFPlayer Mini MP3 Player Module** to play pre-recorded audio files corresponding to each currency value. The project is built on an **Arduino Uno** microcontroller.

---

## 📖 Project Objective

- To assist visually impaired individuals in identifying currency denominations independently.
- To implement a simple, cost-effective hardware system that uses color sensing and audio playback.
- To demonstrate real-time detection and output of currency denomination using embedded hardware components.

---

## 🔧 Components Used

- Arduino Uno             
- TCS3200 Color Sensor   
- DFPlayer Mini MP3 Module
- MicroSD Card            
- 8Ω Speaker              
- Breadboard & Jumper Wires
- 5V Power Supply         

---

## 📊 Block Diagram
![Block_diagram](https://github.com/user-attachments/assets/f7cbc415-5cde-478b-83d7-4d87a4de3c5d)


---

## 📷 Circuit Diagram

![Circuit](https://github.com/user-attachments/assets/e88d20a5-53a9-4ea1-8f1c-e42f5c1967e3)


---

## 📋 Working Explanation

1. The **TCS3200 Color Sensor** captures the color data (RGB values) of the currency note.
2. The Arduino reads these color values and compares them with predefined RGB ranges stored in the code for different denominations.
3. Based on the detected denomination, the Arduino sends a command to the **DFPlayer Mini MP3 Module**.
4. The **DFPlayer Mini** plays the corresponding audio file announcing the currency value through the connected speaker.
5. This allows visually impaired individuals to identify the currency note using audio cues.

---

## 🎶 Audio Files Format

- Store pre-recorded MP3 files in a microSD card inserted into the DFPlayer Mini.
- Name the files as:
  - `001.mp3` → "Ten Rupees"
  - `002.mp3` → "Twenty Rupees"
  - `003.mp3` → "Fifty Rupees"
  - `004.mp3` → "One Hundred Rupees"
  - `005.mp3` → "Two Hundred Rupees"
  - `006.mp3` → "Five Hundred Rupees"

---

## 📝 How to Use

1. Connect the components as per the circuit diagram.
2. Upload the `currency_detector.ino` code to the Arduino Uno.
3. Insert the microSD card with the audio files into the DFPlayer Mini.
4. Power on the system.
5. Place a currency note in front of the color sensor.
6. The system will detect the color combination and announce the denomination via the speaker.

---

## 📊 Future Enhancements

- Integrating a voice command module for better interaction.
- Adding a mobile application for remote control and status display.
- Expanding the system to support future currency updates.

---

## 🙏 Acknowledgements

- Circuit Digest tutorials for hardware interfacing concepts.
- Arduino community for library support.
- Open Source Libraries for DFPlayer Mini and TCS3200.

---

## 📞 Contact

For any queries or collaborations:

**Anand Mohokar**  
Email: anandmohokar09@gmail.com  
GitHub: [github.com/AnandMohokar09](https://github.com/AnandMohokar09)






