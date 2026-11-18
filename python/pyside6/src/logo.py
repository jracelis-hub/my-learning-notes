from PySide6 import QtWidgets 
from PySide6.QtGui import QPixmap

def main():
    
    app = QtWidgets.QApplication()
    
    main_window = QtWidgets.QMainWindow()
    
    main_content = QtWidgets.QFrame(main_window)
    layout = QtWidgets.QGridLayout(main_content)
    
    rivian_logo = QPixmap('..\\images\\rivian-logo.svg')
    image = QtWidgets.QLabel(pixmap = rivian_logo)
    layout.addWidget(image, 0, 0)
    
    main_window.setCentralWidget(main_content)
    main_window.show()

    app.exec()

if __name__ == '__main__':
    main()
