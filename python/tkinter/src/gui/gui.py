import tkinter
from tkinter import ttk

class StartApplication(tkinter.Tk):

    def __init__(self):
        super().__init__() 

        self.title('Service Provisioner')
        
        main_window = MainWindow()

        self.mainloop()

class MainWindow(ttk.Frame):
    def __init__(self):
        self._configs = {
            'relief'     : tkinter.SUNKEN,
            'borderwidth': 2,
            'padding'    : (5, 5, 5, 5)
        }
        super().__init__(**self._configs)

        self.grid()
        self.content_relay_status = RelayStatusContent(self)
        self.content_title = TitleContent(self)
        self.content_entry = EntryContent(self)

class RelayStatusContent(ttk.Labelframe):
    
    def __init__(self, master: tkinter.Widget):
        self._configs = {
            'master' : master,
            'text'   : 'Relay Status',
            'relief' : tkinter.SUNKEN,
            'padding': (20, 20, 10, 10)
        }
        super().__init__(**self._configs)

        self.grid(row = 2, 
                  column = 0,
                  sticky = 'NSEW')

        self.label_on = ttk.Label(self, text = 'On')
        self.label_on.grid(row = 0, column = 1)

        self.label_off = ttk.Label(self, text = 'Off')
        self.label_off.grid(row = 0, column = 2)

        self.label_tcm1 = ttk.Label(self, text = 'TCM1')
        self.label_tcm1.grid(row = 1, 
                             column = 0,
                             sticky = tkinter.E)

        self.label_axm2 = ttk.Label(self, text = 'AXM2')
        self.label_axm2.grid(row = 2, 
                             column = 0,
                             sticky = tkinter.E)

        self.label_axm2p5 = ttk.Label(self, text = 'AXM2.5')
        self.label_axm2p5.grid(row = 3, 
                               column = 0,
                               sticky = tkinter.E)

class TitleContent(ttk.Frame):
    
    def __init__(self, master: tkinter.Widget):
        self._configs = {
            'master': master
        }
        super().__init__(**self._configs)
        
        self.grid(row = 0, column = 1)

        self.label_title = ttk.Label(self, text = 'Service Provisioner',
                                     font = ('Time New Roman', 16, 'bold'))
        self.label_title.grid(row = 0, 
                              column = 0,
                              sticky = tkinter.W)

        self.label_verison = ttk.Label(self, text = 'Version 1.0.0v',
                                       font = ('Times New Roman', 12, 'bold'))
        self.label_verison.grid(row = 1, 
                                column = 0,
                                sticky = tkinter.W)

class EntryContent(ttk.Labelframe):

    def __init__(self, master: tkinter.Widget):
        self._configs = {
            'master' : master,
            'relief' : tkinter.SUNKEN,
            'text'   : 'Entry Data',
            'padding': (10)
        }
        super().__init__(**self._configs)

        self.grid(row = 3, 
                  column = 0, 
                  sticky = 'NWES')
        
        self.label_work_order = ttk.Label(self, text = 'Enter Work Order')
        self.label_work_order.grid(row = 0, 
                                   column = 0,
                                   sticky = tkinter.W)

        self.entry_work_order = tkinter.Entry(self)
        self.entry_work_order.grid(row = 1, 
                                   column = 0,
                                   sticky = tkinter.W)
