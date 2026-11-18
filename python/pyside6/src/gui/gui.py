import sys
from PySide6 import QtWidgets
from PySide6.QtGui import QPixmap
from PySide6.QtCore import Qt
from PySide6.QtGui import QPalette, QColor, QFont

# Need to implement ColorScheme and GlobalColor
# Qt.ColorScheme
# Qt.ColorScheme.Light or Qt.ColorScheme.Dark
#
# Qt.GlobalColor
# Qt.white ---> White (#ffffff)

_FONT_STYLE: str = 'Arial'
_FONT_SIZE: int = 10
_WIDTH_COLUMN_ONE: int = 400
_HEIGHT_COLUMN_ONE: int = 250

class StartGui(QtWidgets.QApplication):

    def __init__(self):
        super().__init__(sys.argv)

        self.main_gui: MainGui() = MainGui()
        
        sys.exit(self.exec_())

class MainGui(QtWidgets.QMainWindow):
        
    def __init__(self):
        super().__init__()

        self.setWindowTitle('Service Provisioner')
        
        self.content_main: MainContent = MainContent()

        self.setCentralWidget(self.content_main)
        self.setStatusBar(self.content_main.bar_status)
        self.setMenuBar(self.content_main.bar_menu)

        self.adjustSize()
        self.setFixedSize(self.size())

        self.show()

class MainContent(QtWidgets.QFrame):

    def __init__(self):
        super().__init__()

        self.create_content()
        self.format_layout()
        self.add_push_button_methods()

    def create_content(self):

        self.layout: QtWidgets.QGridLayout = QtWidgets.QGridLayout(self)
        self.content_rivian_logo: RivianLogoContent = RivianLogoContent(self)
        self.content_relay_status: RelayStatusContent = RelayStatusContent(self)
        self.content_data_entry: DataEntryContent = DataEntryContent(self)
        self.content_title: TitleContent = TitleContent(self)
        self.content_meta_data: MetaDataContent = MetaDataContent(self)
        self.content_terminal: TerminalContent = TerminalContent(self)
        self.bar_status: StartResetContent = StartResetContent(self)
        self.bar_menu: MenuContent = MenuContent(self)

    def format_layout(self):

        self.layout.addWidget(self.content_rivian_logo, 0, 0, 2, 1)
        self.layout.addWidget(self.content_relay_status, 2, 0, 1, 1)
        self.layout.addWidget(self.content_data_entry, 3, 0, 1, 1)
        self.layout.addWidget(self.content_title, 0, 1, 1, 1)
        self.layout.addWidget(self.content_meta_data, 0, 2, 2, 1)
        self.layout.addWidget(self.content_terminal, 2, 1, 2, 2)
    
    def add_push_button_methods(self):

        self.bar_status.push_button_start.clicked.connect(self.app_start)
        self.bar_status.push_button_reset.clicked.connect(self.app_reset)

    def app_start(self):
        """Starts the application to begin provisioning task"""
        print('Hello start')
        pass

    def app_reset(self):
        """Resets the state of the application"""
        print('Hello reset')
        pass

class MenuContent(QtWidgets.QMenuBar):
    
    def __init__(self, parent: QtWidgets.QWidget):
        super().__init__(parent)

class RelayStatusContent(QtWidgets.QGroupBox):

    _FIXED_WIDTH: int = _WIDTH_COLUMN_ONE
    _FIXED_HEIGHT: int  = _HEIGHT_COLUMN_ONE

    def __init__(self, parent: QtWidgets.QWidget = None):
        super().__init__('Relay Status', parent)

        self.create_content()
        self.format_font()
        self.format_state()
        self.format_color()
        self.format_layout()

    def create_content(self):

        self.layout = QtWidgets.QGridLayout(self)

        self.label_on: QtWidgets.QLabel = QtWidgets.QLabel('On')
        self.label_off: QtWidgets.QLabel = QtWidgets.QLabel('Off')

        self.label_tcm1: QtWidgets.QLabel = QtWidgets.QLabel('TCM1')
        self.label_axm2: QtWidgets.QLabel = QtWidgets.QLabel('AXM2')
        self.label_axm2p5: QtWidgets.QLabel = QtWidgets.QLabel('AXM2.5')

        self.checkbox_on_tcm1: QtWidgets.QCheckBox = QtWidgets.QCheckBox()
        self.checkbox_on_axm2: QtWidgets.QCheckBox = QtWidgets.QCheckBox()
        self.checkbox_on_axm2p5: QtWidgets.QCheckBox = QtWidgets.QCheckBox()

        self.checkbox_off_tcm1: QtWidgets.QCheckBox = QtWidgets.QCheckBox()
        self.checkbox_off_axm2: QtWidgets.QCheckBox = QtWidgets.QCheckBox()
        self.checkbox_off_axm2p5: QtWidgets.QCheckBox = QtWidgets.QCheckBox()

        self.setFixedSize(self._FIXED_WIDTH, self._FIXED_HEIGHT)

    def format_font(self):

        self.font: QFont = QFont(_FONT_STYLE, _FONT_SIZE)
        self.font.setBold(True)
        self.setFont(self.font)

    def format_color(self):

        self.palette_on: QPalette = QPalette()
        self.palette_on.setColor(QPalette.ColorGroup.Active, QPalette.ColorRole.Button, Qt.darkGreen)
        self.palette_off: QPalette = QPalette()
        self.palette_off.setColor(QPalette.ColorRole.Button, Qt.red)

        self.checkbox_on_tcm1.setPalette(self.palette_on)
        self.checkbox_on_axm2.setPalette(self.palette_on)
        self.checkbox_on_axm2p5.setPalette(self.palette_on)

        self.checkbox_off_tcm1.setPalette(self.palette_off)
        self.checkbox_off_axm2.setPalette(self.palette_off)
        self.checkbox_off_axm2p5.setPalette(self.palette_off)

    def format_state(self):

        self.checkbox_on_tcm1.setEnabled(False)
        self.checkbox_on_axm2.setEnabled(False)
        self.checkbox_on_axm2p5.setEnabled(False)

    def format_layout(self):

        self.layout.addWidget(self.label_on, 0, 1)
        self.layout.addWidget(self.label_off, 0, 2)
        self.layout.addWidget(self.label_tcm1, 1, 0)
        self.layout.addWidget(self.label_axm2, 2, 0)
        self.layout.addWidget(self.label_axm2p5, 3, 0)
        self.layout.addWidget(self.checkbox_on_tcm1, 1, 1)
        self.layout.addWidget(self.checkbox_on_axm2, 2, 1)
        self.layout.addWidget(self.checkbox_on_axm2p5, 3, 1)
        self.layout.addWidget(self.checkbox_off_tcm1, 1, 2)
        self.layout.addWidget(self.checkbox_off_axm2, 2, 2)
        self.layout.addWidget(self.checkbox_off_axm2p5, 3, 2)
        

class DataEntryContent(QtWidgets.QGroupBox):

    _FIXED_WIDTH: int = _WIDTH_COLUMN_ONE
    _FIXED_HEIGHT: int = _HEIGHT_COLUMN_ONE
    _ALIGNMENT_LEFT: Qt.AlignmentFlag = Qt.AlignLeft

    def __init__(self, parent: QtWidgets.QWidget = None):
        super().__init__('Data Entry', parent)

        self.create_content()
        self.format_layout()
        self.format_font()

    def create_content(self):

        self.layout = QtWidgets.QGridLayout(self)

        self.label_work_order_entry: QtWidgets.QLabel = QtWidgets.QLabel('Enter Work Order:')
        self.line_edit_work_order: QtWidgets.QLineEdit = QtWidgets.QLineEdit() 
        self.line_edit_work_order.setFixedSize(self._FIXED_WIDTH - 20, 20)

        self.label_qr_code: QtWidgets.QLabel = QtWidgets.QLabel('Enter QR Code:')
        self.line_edit_qr_code: QtWidgets.QLineEdit = QtWidgets.QLineEdit()
        self.line_edit_qr_code.setFixedSize(self._FIXED_WIDTH - 20, 20)

        self.setFixedSize(self._FIXED_WIDTH, self._FIXED_HEIGHT)

    def format_font(self):

        self.font: QFont = QFont(_FONT_STYLE, _FONT_SIZE)
        self.font.setBold(True)
        self.setFont(self.font)

    def format_layout(self):

        self.layout.addWidget(self.label_work_order_entry, 0, 0, alignment = self._ALIGNMENT_LEFT)
        self.layout.addWidget(self.line_edit_work_order, 1, 0, alignment = self._ALIGNMENT_LEFT)
        self.layout.addWidget(self.label_qr_code, 2, 0, alignment = self._ALIGNMENT_LEFT)
        self.layout.addWidget(self.line_edit_qr_code, 3, 0, alignment = self._ALIGNMENT_LEFT)


class TitleContent(QtWidgets.QFrame):
    
    _FIXED_WIDTH: int = 450    
    _ALIGNMENT_TOP_LEFT: Qt.AlignmentFlag = Qt.AlignTop | Qt.AlignLeft

    def __init__(self, parent: QtWidgets.QWidget = None):
        super().__init__(parent)

        #self.setFrameStyle(QtWidgets.QFrame.Shadow.Sunken | QtWidgets.QFrame.Shape.WinPanel)

        self.layout: QtWidgets.QVBoxLayout = QtWidgets.QGridLayout(self)
        
        self.font_title: QFont = QFont(_FONT_STYLE, 24)
        self.font_title.setBold(True)
        self.label_title: QtWidgets.QLabel = QtWidgets.QLabel('Service Provisioner')
        self.label_title.setFont(self.font_title)

        self.font_title.setPointSize(18)
        self.label_version: QtWidgets.QLabel = QtWidgets.QLabel('Version: 1.0.0v')
        self.label_version.setFont(self.font_title)
        
        self.layout.addWidget(self.label_title, 0, 0, alignment = self._ALIGNMENT_TOP_LEFT)
        self.layout.addWidget(self.label_version, 1, 0, alignment = self._ALIGNMENT_TOP_LEFT)

        self.setMinimumWidth(self._FIXED_WIDTH)

class RivianLogoContent(QtWidgets.QLabel):

    _FIXED_WIDTH: int = _WIDTH_COLUMN_ONE
    _FIXED_HEIGHT: int = _HEIGHT_COLUMN_ONE

    def __init__(self, parent: QtWidgets.QWidget = None):
        super().__init__(parent)

        #self.qpixmap_rivian_logo: QPixmap = QPixmap('..\\images\\rivian-logo.svg')
        self.qpixmap_rivian_logo: QPixmap = QPixmap('..\\images\\logo.png')
        self.setPixmap(self.qpixmap_rivian_logo)
        self.setScaledContents(True)

        self.setFixedSize(self._FIXED_WIDTH, self._FIXED_HEIGHT)

class MetaDataContent(QtWidgets.QFrame):

    _MINIMUM_HEIGHT_LABEL: int = 2
    _MINIMUM_WIDTH_LABEL: int = 200
    _ALIGNMENT_LABEL: Qt.AlignmentFlag = Qt.AlignRight
    _FRAME_SHAPE: QtWidgets.QFrame.Shape = QtWidgets.QFrame.Shape.WinPanel
    _FRAME_SHADOW: QtWidgets.QFrame.Shadow = QtWidgets.QFrame.Shadow.Sunken
    _LINE_WIDTH: int = 2

    def __init__(self, parent: QtWidgets.QWidget = None):
        super().__init__(parent)

        self.layout: QtWidgets.QGridLayout = QtWidgets.QGridLayout(self)
        self.setFrameStyle(QtWidgets.QFrame.Shadow.Raised | QtWidgets.QFrame.Shape.WinPanel)
        self.font: QFont = QFont(_FONT_STYLE, _FONT_SIZE)
        self.font.setBold(True)
        self.setFont(self.font)

        self.label_work_order: QtWidgets.QLabel = QtWidgets.QLabel('Work Order')
        self.label_vin: QtWidgets.QLabel = QtWidgets.QLabel('VIN')
        self.label_part_number: QtWidgets.QLabel = QtWidgets.QLabel('Part Number')
        self.label_serial_number: QtWidgets.QLabel = QtWidgets.QLabel('Serial Number')
        self.label_vehicle_type: QtWidgets.QLabel = QtWidgets.QLabel('Vehicle Type')
        
        self.label_work_order_data: QtWidgets.QLabel = QtWidgets.QLabel()
        self.label_vin_data: QtWidgets.QLabel = QtWidgets.QLabel()
        self.label_part_number_data: QtWidgets.QLabel = QtWidgets.QLabel()
        self.label_serial_number_data: QtWidgets.QLabel = QtWidgets.QLabel()
        self.label_vehicle_type_data: QtWidgets.QLabel = QtWidgets.QLabel()

        self.label_work_order_data.setFrameShape(self._FRAME_SHAPE) 
        self.label_work_order_data.setFrameShadow(self._FRAME_SHADOW)
        self.label_work_order_data.setLineWidth(self._LINE_WIDTH)

        self.label_vin_data.setFrameShape(self._FRAME_SHAPE) 
        self.label_vin_data.setFrameShadow(self._FRAME_SHADOW)
        self.label_vin_data.setLineWidth(self._LINE_WIDTH)

        self.label_part_number_data.setFrameShape(self._FRAME_SHAPE) 
        self.label_part_number_data.setFrameShadow(self._FRAME_SHADOW)
        self.label_part_number_data.setLineWidth(self._LINE_WIDTH)

        self.label_serial_number_data.setFrameShape(self._FRAME_SHAPE) 
        self.label_serial_number_data.setFrameShadow(self._FRAME_SHADOW)
        self.label_serial_number_data.setLineWidth(self._LINE_WIDTH)

        self.label_vehicle_type_data.setFrameShape(self._FRAME_SHAPE) 
        self.label_vehicle_type_data.setFrameShadow(self._FRAME_SHADOW)
        self.label_vehicle_type_data.setLineWidth(self._LINE_WIDTH)

        self.label_work_order_data.setMinimumSize(self._MINIMUM_WIDTH_LABEL, self._MINIMUM_HEIGHT_LABEL)
        self.label_vin_data.setMinimumSize(self._MINIMUM_WIDTH_LABEL, self._MINIMUM_HEIGHT_LABEL)
        self.label_part_number_data.setMinimumSize(self._MINIMUM_WIDTH_LABEL, self._MINIMUM_HEIGHT_LABEL)
        self.label_serial_number_data.setMinimumSize(self._MINIMUM_WIDTH_LABEL, self._MINIMUM_HEIGHT_LABEL)
        self.label_vehicle_type_data.setMinimumSize(self._MINIMUM_WIDTH_LABEL, self._MINIMUM_HEIGHT_LABEL)

        self.layout.addWidget(self.label_work_order, 0, 0, alignment = self._ALIGNMENT_LABEL)
        self.layout.addWidget(self.label_vin, 1, 0, alignment = self._ALIGNMENT_LABEL)
        self.layout.addWidget(self.label_part_number, 2, 0, alignment = self._ALIGNMENT_LABEL)
        self.layout.addWidget(self.label_serial_number, 3, 0, alignment = self._ALIGNMENT_LABEL)
        self.layout.addWidget(self.label_vehicle_type, 4, 0, alignment = self._ALIGNMENT_LABEL)

        self.layout.addWidget(self.label_work_order_data, 0, 1)
        self.layout.addWidget(self.label_vin_data, 1, 1)
        self.layout.addWidget(self.label_part_number_data, 2, 1)
        self.layout.addWidget(self.label_serial_number_data, 3, 1)
        self.layout.addWidget(self.label_vehicle_type_data, 4, 1)

class TerminalContent(QtWidgets.QTabWidget):
    def __init__(self, parent: QtWidgets.QWidget):
        super().__init__(parent)

        self.main_palette: QPalette = self.palette()
        self.setPalette(self.main_palette)

        self.console: QtWidgets.QPlainTextEdit = QtWidgets.QPlainTextEdit()
        self.palette: QPalette = self.console.palette()
        self.console.setAutoFillBackground(True)
        self.palette.setColor(QPalette.ColorGroup.Normal, QPalette.ColorRole.Base, Qt.black)
        self.palette.setColor(QPalette.ColorGroup.Disabled, QPalette.ColorRole.Window, Qt.black)
        self.palette.setColor(QPalette.ColorGroup.Normal, QPalette.ColorRole.Text, Qt.white)
        self.console.setPalette(self.palette)
        self.console.setReadOnly(True)

        self.font: QFont = QFont(_FONT_STYLE, _FONT_SIZE)
        self.font.setBold(True)
        self.setFont(self.font)

        self.layout: QtWidgets.QVBoxLayout = QtWidgets.QVBoxLayout(self)
        self.layout.addWidget(self.console)
    
        self.addTab(self.console, 'Console')

    def console_clear(self) -> None:
        """Clears all the output on the console"""
        pass
    
    def console_write(self, output_type: str) -> None:
        """Writes console output type onto the display"""
        pass

class StartResetContent(QtWidgets.QStatusBar):
    def __init__(self, parent: QtWidgets.QWidget):
        super().__init__(parent)

        self.setAutoFillBackground(True)

        self.font: QFont = QFont(_FONT_STYLE, _FONT_SIZE)
        self.font.setBold(True)
        self.setFont(self.font)
        
        self.main_palette: QPalette = self.palette()
        self.main_palette.setColor(QPalette.ColorRole.Window, Qt.transparent)
        self.setPalette(self.main_palette)

        self.palette: QPalette = QPalette()

        self.push_button_start: QtWidgets.QPushButton = QtWidgets.QPushButton('Start')
        self.palette.setColor(QPalette.ColorRole.Button, Qt.darkGreen)
        self.push_button_start.setPalette(self.palette)

        self.push_button_reset: QtWidgets.QPushButton = QtWidgets.QPushButton('Reset')
        self.palette.setColor(QPalette.ColorRole.Button, Qt.red)
        self.push_button_reset.setPalette(self.palette)

        self.progress_bar: QtWidgets.QProgressBar = QtWidgets.QProgressBar()
        
        self.addPermanentWidget(self.push_button_start)
        self.addPermanentWidget(self.push_button_reset)
        self.addWidget(self.progress_bar)
