def to_binary(d):
    b = ''
    while True:
        if d == 0:
            break
        elif (d % 2) == 0:
            d = d // 2
            b = '0' + b
        else:
            d = d // 2
            b = '1' + b
    return b

def from_binary(binary):
    binary = binary[::-1]
    d = 0
    power = 0 
    for i in binary:
        d += int(i) * (2 ** power)
        power +=1 
    return d 

def addition(a, b):
    max_len = max(len(a), len(b))

    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ''    
    temp = 0

    for i in range(max_len - 1, - 1, - 1):
        num = int(a[i]) + int(b[i]) + temp
        print(num)

        if num % 2 == 0:
            result = '0' + result
        else:
            result = '1' + result

        if num == 2:
            temp = 1
        else:
            temp = 0
    
    if temp !=0: 
        result = '01' + result
    
    if int(result) == 0:
        result = 0

    return result

def subtraction(a, b):
    max_len = max(len(a), len(b))

    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ''    
    temp = 0

    for i in range(max_len - 1, - 1, - 1):
        num = int(a[i]) - int(b[i]) - temp
        if num % 2 == 1:
            result = '1' + result
        else:
            result = '0' + result

        if num < 0:
            temp = 1
        else:
            temp = 0
    
    if temp !=0: 
        result = '01' + result
    
    if int(result) == 0:
        result = 0

    return result

def multiplication(a, b):
    max_len = max(len(a), len(b))
    min_len = min(len(a), len(b))

    result = ''
    temp_result = ''

    temp = []
    zeroes = 0
    temp_index = 0

    for j in range(min_len - 1, - 1, - 1):
        
        temp_result = ''
        for i in range(max_len - 1, - 1, - 1):
            summ = int(a[i]) * int(b[j])
            if summ == 0:
                temp_result = '0' + temp_result
            elif summ == 1:
                temp_result = '1' + temp_result
        temp_result = temp_result + ('0' * zeroes)
        zeroes += 1
        
        temp.append(temp_result)

        if len(temp) == 2:
            result = addition(str(temp[0]), str(temp[1]))
        elif len(temp) > 2:
            temp_index = len(temp)
            temp_index += 1
            result = addition(str(result), str(temp[temp_index - 2]))
        else:
            pass
    return result

def division(a, b):
    result = ''
    temp = '0'
    r = 0

    for i in range(len(a)):        
        if int(b) > int(temp):
            result += '0'
            temp += a[i]
        else:
            r = subtraction(temp, b)
            if r == 0:
                temp = a[i]
                result += '1'
            else:
                r = str(r).lstrip('0')
                result += '1'
                temp = r + a[i]
    
    if temp !=int(0): 
        result = result + '0' 
                
    return result

# Input numbers
a = input('Enter first number: ')
b = input('Enter second number: ')
c = input('Enter operation(+-/*): ')

a = int(a)
b = int(b)

# Converting to binary
ab = to_binary(a)
bb = to_binary(b)

print("In decimal: ", a, '. In binary: ', ab)
print("In decimal: ", b, '. In binary: ', bb)

# Calculation
if c == '+':
    r = addition(ab, bb)
elif c  == '-':
    r = subtraction(ab, bb)
elif c == '*':
    r = multiplication(ab, bb)
elif c == '/':
    r = division(ab, bb)

# Converting to decimal
rd = from_binary(r)

print('Result in binary:', r)
print('Result in decimal:', rd)
