# AI-Vision-Control-Modules

Python-based computer vision modules using OpenCV and MediaPipe for interactive gesture and facial recognition.

---

##📷 Face Detection with Label Overlay

### Overview
This module detects faces via webcam using OpenCV’s Haar Cascade and displays a pink rectangle with a custom label above each detected face.

### Requirements
- Python 3.x  
- OpenCV (`cv2`)

### Behavior
- Captures webcam stream.
- Converts frames to grayscale.
- Detects faces using Haar Cascade Classifier.
- Draws rectangle around each face.
- Prints `"MBS"` label above each face.

### Challenges Faced
- **Classifier loading issue** resolved using `cv2.data.haarcascades`.
- Adjusted label position to avoid overlap.
- Tuned pink color to `(180, 105, 255)` for visibility.

### Future Improvements
- Replace Haar with DNN face detector.
- Integrate personalized name recognition.
- Add audio or external LED response on face detection.

---


##  Finger Counting with Gesture Recognition

### Overview
Tracks a single hand, counts raised fingers, and classifies gestures using MediaPipe and OpenCV.

### Requirements
- Python 3.x  
- OpenCV  
- MediaPipe

### Behavior
- Tracks hand landmarks.
- Counts raised fingers.
- Classifies gestures:
  - Thumb → `Thumb raised`
  - Index → `Index finger raised`
  - Two → `Two fingers raised`
  - Three → `Three fingers raised`
  - Full hand → `Full hand open`
  - No fingers → `Closed fist`

### Challenges Faced
- Hand orientation affected detection.
- Thumb required X-axis logic.
- Emojis removed for screen compatibility.

### Future Improvements
- Add Arduino serial link to send commands.
- Display gesture info on external LCD.
- Expand system for multi-hand input.

---

**⭐ Created by Alyaa**
