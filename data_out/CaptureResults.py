import time
import csv
import serial
import pickle
import os 
import random

# words = sorted(['_silence_','one', 'two','three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'zero', 'yes', 'no'])
words = sorted(['yes','no'])

device_path = '/dev/tty.usbmodem1463401'

random.seed(12314)
count = len([f for f in os.listdir() if f.endswith('.txt')])

is_connected = False
is_error = False

while (True):

    try:
        if not is_connected:
            ser = serial.Serial(device_path, baudrate=500000) # , parity=serial.PARITY_ODD,stopbits=serial.STOPBITS_ONE)
            
            ser.flushInput()
            is_connected = True
        
        if not is_error:
            count += 1
            word = random.choice(words)
        
        time.sleep(1)
        print(word, flush=True)
        lines = []
        is_complete = False

        heard_word = ''
        
        while not is_complete:
            line = ser.readline().decode('utf-8')
            lines.append(line)
            print(line)
            is_complete = 'Complete' in line

            if 'Heard yes' in line:
                heard_word='yes'
            elif 'Heard no' in line:
                heard_word='no'

        with open(f'results_{count:04}_{word}_{heard_word}.txt','w') as f:
            for l in lines:
                f.write(l)
        
        is_error = False

    except KeyboardInterrupt as interrupt:
        exit()
    except Exception as ex:
        is_connected = False
        is_error = True
        # print(f'{ex}', end='', flush=True)

# for w in range(len(words) * 100):

#     word = words[w % len(words)]
#     print(word)

#     file_prefix = f'audio_{word}_'
#     file_count = [f for f in os.listdir() if f.startswith(file_prefix) and f.endswith('.pkl')]

#     file_number = 1 # len(file_count) + 1
#     audio_file = f'{file_prefix}_{file_number}.pkl'
#     while os.path.exists(audio_file):
#         file_number += 1
#         audio_file = f'{file_prefix}_{file_number}.pkl'

#     with open(audio_file, 'wb') as f:

#         index = 0
#         data = b''

#         while index < 22400 * 1:
#             try:
#                 encoded_bytes = ser.read_all()
#                 data += encoded_bytes

#                 if b'\r\n' in encoded_bytes:
#                     index += encoded_bytes.count(b'\r\n')

#             except Exception as ex:
#                 print(f"Keyboard interrupt: {ex}")
#                 break

#         to_int = lambda x : int(x) if len(x) > 0 else 0
#         decode = lambda x : x.decode("utf-8").replace('\r\n','')
#         raw_values = data.split(b'\r\n')

#         samples = [to_int(decode(d)) for d in raw_values]

#         pickle.dump(samples, f)
