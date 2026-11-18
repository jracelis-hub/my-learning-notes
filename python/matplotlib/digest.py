import csv
from matplotlib import figure, axes

_FILE_TYPES = (
    'swr',
    's11',
    'smith',
    's21'
    )

class Digest():

    def __init__(self, 
                file_type: str, 
                /, 
                *, 
                plot_title: str, 
                plot_axisx,
                plot_axisy,
                **kwargs):
        self._file_type = file_type
        self._plot_title = 
        self._plot_axisx = 
        self._plot_axisy = 

    def _create_figure(self):
        settings = {
            'random': 'random',
            'something': True
        }
        main_figure: figure.Figure = figure.Figure(**settings)
        
