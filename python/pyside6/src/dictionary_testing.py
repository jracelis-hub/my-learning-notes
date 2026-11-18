class Filler:
    
    def __init__(self):
        self.filler = 'seomthing'

class DictionaryTest:
    
    def __init__(self):
        self.layout_work_order = Filler()
        self.layout_work_order_data = Filler()
        self.layout_vehicle_type = Filler()
        self.layout_vehicle_type_data = Filler()

def main():
    
    test: DictionaryTest = DictionaryTest()
    
    for key, value in test.__dict__.items():
        if key.endswith('data'):
            print(key)
            print(value)
    

if __name__ == '__main__':
    main()
