import cv2 as cv
from teste2 import pictureCapture

PENTAGON = 1
TRIANGLE = 2
SQUARE = 3
STAR = 4
HALF_CIRCLE = 5
CIRCLE = 6

def indetifyObject(img):
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    ret, thresh = cv.threshold(gray, 127, 255, 1)

    contours, h = cv.findContours(thresh, 1, 2)

    for cnt in contours:
        approx = cv.approxPolyDP(cnt, 0.01 * cv.arcLength(cnt, True), True)
        print(len(approx))
    if len(approx) == 5:
        print("pentagon")
        cv.drawContours(img, [cnt], 0, 255, -1)
        return 1
    elif len(approx) == 3:
        print("triangle")
        cv.drawContours(img, [cnt], 0, (0, 255, 0), -1)
        return 2
    elif len(approx) == 4:
        print("square")
        cv.drawContours(img, [cnt], 0, (0, 0, 255), -1)
        return 3
    elif len(approx) == 5:
        print("star")
        cv.drawContours(img, [cnt], 0, (0, 0, 255), -1)
        return 4
    elif len(approx) == 9:
        print("half-circle")
        cv.drawContours(img, [cnt], 0, (255, 255, 0), -1)
        return 5
    elif len(approx) > 15:
        print("circle")
        cv.drawContours(img, [cnt], 0, (0, 255, 255), -1)
        return 6



if __name__ == '__main__':
    pictureCapture(1)
    img = cv.imread("1.jpeg")
    form = indetifyObject(img)
    print(form)
    cv.imshow('img', img)
    cv.waitKey(0)
    cv.destroyAllWindows()
