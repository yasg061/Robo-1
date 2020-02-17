import serial

print('-------PEDALS MOVEMENT-----\n')
print('A : UP PEDAL ACTIVATED')
print('B : UP PEDAL DISABLED')
print('C : DOWN PEDAL DISABLED')
print('D : DOWN PEDAL ACTIVATED\n')

arduino = serial.Serial("COM3", 9600)

while True:
    var = input('Enter a variable >')

    if var == 'A':
        print('A : UP PEDAL ACTIVATED')
        arduino.write(str.encode('A'))
    elif var == 'B':
        print('B : UP PEDAL DISABLED')
        arduino.write(str.encode('B'))
    elif var == 'C':
        print('C : DOWN PEDAL DISABLED')
        arduino.write(str.encode('C'))
    elif var == 'D':
        print('D : DOWN PEDAL ACTIVATED')
        arduino.write(str.encode('D'))
    else:
        print('INVALID VARIABLE')
    print()
        
        

