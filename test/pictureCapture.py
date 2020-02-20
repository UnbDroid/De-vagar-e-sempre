import cv2 as cv

  
def pictureCapture(num):
    captura = cv.VideoCapture(0)
    ret, frame = captura.read()
    cv.imwrite(str(num)+".jpeg", frame)
    captura.release()

if __name__ == '__main__':
    pictureCapture(1)
    img = cv.imread("1.jpeg")
    cv.imshow("img", img)
    cv.waitKey(0)
    cv.destroyAllWindows()
