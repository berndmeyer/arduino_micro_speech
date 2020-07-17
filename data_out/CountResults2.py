import os

files = [f for f in os.listdir() if f.endswith('.txt')]

no_score_prefix = 'AvgScore 0 '
yes_score_prefix = 'AvgScore 1 '

yy_count = 0
yn_count = 0
nn_count = 0
ny_count = 0

# print(f'{f}, {word}, {max_word}, {no_score}, {yes_score}')
print('Filename, word, prediction, no_score, yes_score')

for f in files:

    word = 'yes'

    if '_no_no' in f or '_no_.' in f or '_no_yes' in f:
        word = 'no'

    with open(f, 'r') as d:
        lines = d.readlines()

        yes_score = 0
        no_score = 0

        for l in lines:
            if yes_score_prefix in l:
                # print(l)
                yes_score = int(l[11:])
            elif no_score_prefix in l:
                # print(l)
                no_score = int(l[11:])
    
    max_word = 'yes' if yes_score > no_score else 'no'

    print(f'{f}, {word}, {max_word}, {no_score}, {yes_score}')

    if word is 'yes' and max_word is 'yes':
        yy_count += 1
    elif word is 'no' and max_word is 'no':
        nn_count += 1
    elif word is 'yes' and max_word is 'no':
        yn_count += 1 
    elif word is 'no' and max_word is 'yes':
        ny_count += 1

print(f'YY {yy_count} {yy_count / (yy_count + yn_count)}')
print(f'YN {yn_count} {yn_count / (yy_count + yn_count)}')
print(f'NN {nn_count} {nn_count / (nn_count + ny_count)}')
print(f'NY {ny_count} {ny_count / (nn_count + ny_count)}')

