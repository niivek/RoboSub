def direction_finder(x, y):
    if x < 0:
        print('move left by {}'.format(x))
        #direct AUV to move to the left by x 
    elif x > 0:
        print('move right by {}'.format(x))
        #direct AUV to move to the right by x 
    else:
        print('hold x position')
        #direct AUV to hold x position
    if y < 0:
        print('move down by {}'.format(y))
        #direct AUV to move up by y
    elif y > 0:
        print('move up by {}'.format(y))
        #direct AUV to move down by y
    else:
        print('hold y position')
        #direct AUV to hold y position
    if x > 0 and y > 0:
        print('Sub must move towards quadrant 1')
    elif x < 0 and y > 0:
        print('Sub must move towards quadrant 2')
    elif x < 0 and y < 0:
        print('Sub must move towards quadrant 3')
    elif x > 0 and y < 0:
        print('Sub must move towards quadrant 4')

def check_hardware(statement):
    print('checking hardware...\n')
    motorNodeIsReady = statement
    cvNodeIsready = statement
    startTakingPicture = statement
    
    if motorNodeIsReady:
        print('motor node is on...')
    if cvNodeIsready:
        print('cv node is on...')
    if startTakingPicture:
        print('picture taking node is on...\n')

    print('hardware is now active and ready\n')

def turn_off_hardware():
    motorNodeIsReady = False
    cvNodeIsready = False
    startTakingPicture = False
    print('hardware nodes have now been turned off')


def main():
    motorNodeIsReady = False
    cvNodeIsready = False
    startTakingPicture = False

    check_hardware(True)

    test_x = -20
    test_y = -30
    direction_finder(test_x, test_y)
    print('')

    test_x = 0
    test_y = 60
    direction_finder(test_x, test_y)
    print('')

    test_x = 20
    test_y = 0
    direction_finder(test_x, test_y)
    print('')

    test_x = 0
    test_y = 0
    direction_finder(test_x, test_y)
    print('')

    test_x = -30
    test_y = 40
    direction_finder(test_x, test_y)
    print('')
    
    turn_off_hardware()

if __name__ == "__main__":
    main()