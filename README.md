# AI-Vision-Control-Modules
Python-based computer vision modules using OpenCV and MediaPipe for interactive gesture and facial recognition.

Face Detection with Label Overlay
Overview
This module detects human faces via webcam using OpenCV’s Haar Cascade Classifier, then overlays a custom label ("MBS") above each detected face in real-time. The system is designed for AI-driven recognition environments such as interactive kiosks or exhibition showcases.

Requirements
Python 3.x

OpenCV (cv2)

Behavior
Captures video stream from default webcam.

Converts frames to grayscale for face detection.

Detects faces using Haar Cascades.

Draws a pink rectangle around each detected face.

Displays label "MBS" above each detected face with increased font size.

Challenges Faced
Classifier Loading Error

Issue: The .xml cascade file was missing or improperly referenced.

Solution: Used cv2.data.haarcascades to reliably locate built-in models.

Text Positioning Above Face

Issue: Label overlap with rectangle.

Solution: Adjusted y-offset to position text above the top-left corner of the bounding box.

Custom Color Rendering

Issue: Non-standard RGB values rendered incorrectly.

Solution: Used tuple (180, 105, 255) to get accurate light pink hue.

Future Improvements
Add name recognition from a pre-trained classifier for personalized labels.

Integrate audio welcome message when a face is detected.

Replace Haar Cascade with DNN-based face detector for higher precision.

Finger Counting with Gesture Classification
Overview
This module uses MediaPipe Hands and OpenCV to track a single hand, count raised fingers, and classify specific gestures based on finger patterns. It provides foundational logic for gesture-controlled systems.

Requirements
Python 3.x

OpenCV (cv2)

MediaPipe

Behavior
Tracks hand landmarks using MediaPipe.

Counts raised fingers based on position of finger tips.

Classifies specific gestures:

Thumb raised → "Thumb raised"

Index finger only → "Index finger raised"

Two or three fingers → "Two fingers raised", "Three fingers raised"

Full hand open → "Full hand open"

Closed fist → "Closed fist"

Displays real-time feedback on screen.

Challenges Faced
Thumb Axis Ambiguity

Issue: Thumb detection required X-axis comparison unlike other fingers.

Solution: Separated thumb logic using its horizontal axis and added manual calibration.

Misalignment with Hand Orientation

Issue: Finger detection failed when hand tilted.

Solution: Restricted detection to ideal frontal hand pose.

Text Visibility Issues

Issue: Emojis displayed as question marks.

Solution: Removed all emojis and used pure English labels for clarity.

Future Improvements
Add multi-hand support for dual-user applications.

Connect gestures to control Arduino modules (e.g., turn motor ON with 2-finger gesture).

Display gesture name and confidence level on external LCD.

This repository features two AI-powered recognition modules using Python, suitable for interactive learning and exhibition systems.

⭐ Created by Alyaa
