import serial

print('-------PEDALS MOVEMENT-----\n')
print('A : UP PEDAL ACTIVATED')
print('B : UP PEDAL DISABLED')
print('C : DOWN PEDAL DISABLED')
print('D : DOWN PEDAL ACTIVATED\n')

#arduino = serial.Serial('/dev/ttyACM0', 9600)

while True:
    var = input('Enter a variable >')

    if var == 'A':
        print('A : UP PEDAL ACTIVATED')
        #arduino.write(var)
    elif var == 'B':
        print('B : UP PEDAL DISABLED')
        #arduino.write(var)
    elif var == 'C':
        print('C : DOWN PEDAL DISABLED')
        #arduino.write(var)
    elif var == 'D':
        print('D : DOWN PEDAL ACTIVATED')
        #arduino.write(var)
    else:
        print('INVALID VARIABLE')
    print()
        
        

