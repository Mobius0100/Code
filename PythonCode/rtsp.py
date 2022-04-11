import cv2

#cap = cv2.VideoCapture("rtsp://admin:asd123456@192.168.0.64:554/Streaming/Channels/101")
cap = cv2.VideoCapture("rtsp://admin:admin@192.168.0.184:554/stream1")
ret, frame = cap.read()

while ret:
    ret, frame = cap.read()
    cv2.imshow("frame",frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
cap.release()