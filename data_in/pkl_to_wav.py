import pickle
from scipy.io.wavfile import write
import os
import numpy as np

sample_rate = 16000  #16000
overwrite = False

for audio_file in [f.replace('.pkl','') for f in os.listdir() if f.endswith('.pkl') and f.startswith('audio_')]:

    try:

        # audio_file = 'audio_eight__2'

        pkl_file = f'{audio_file}.pkl'
        wav_file = f'{audio_file}.wav'

        if overwrite or not os.path.exists(wav_file):
            with open(pkl_file, 'rb') as p:
                samples = pickle.load(p)

            data = np.array(samples[6400:], dtype=np.int16)

            write(wav_file, sample_rate, data)

            print(f'{data.min()} {data.max()} {data.mean()}')

    except Exception as ex:
        print(f'Skipping {audio_file}. {ex}')
        