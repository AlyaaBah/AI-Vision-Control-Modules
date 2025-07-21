import cv2
import mediapipe as mp

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1)
mp_draw = mp.solutions.drawing_utils
finger_tips = [4, 8, 12, 16, 20]

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    img_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)

    gesture = ""

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

            fingers = []

            if hand_landmarks.landmark[finger_tips[0]].x < hand_landmarks.landmark[finger_tips[0] - 1].x:
                fingers.append(1)
            else:
                fingers.append(0)

            for tip in finger_tips[1:]:
                if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
                    fingers.append(1)
                else:
                    fingers.append(0)

            total_fingers = sum(fingers)

            if fingers == [1, 0, 0, 0, 0]:
                gesture = "Thumb raised"
            elif fingers == [0, 1, 0, 0, 0]:
                gesture = "Index finger raised"
            elif fingers == [0, 1, 1, 0, 0]:
                gesture = "Two fingers raised"
            elif fingers == [0, 1, 1, 1, 0]:
                gesture = "Three fingers raised"
            elif total_fingers == 5:
                gesture = "Full hand open"
            elif total_fingers == 0:
                gesture = "Closed fist"
            else:
                gesture = f"{total_fingers} fingers raised"

    cv2.putText(frame, gesture, (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1.2, (0, 255, 0), 2)
    cv2.imshow("Hand Gesture Detection", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
