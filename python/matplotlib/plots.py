from matplotlib import pyplot

def main():
    
    x = list()
    y = list()

    for value in range(10):
        x.append(value)         
        y.append(value)         

    fig: Figure = pyplot.figure()

    pyplot.show() 

if __name__ == '__main__':
    main()
