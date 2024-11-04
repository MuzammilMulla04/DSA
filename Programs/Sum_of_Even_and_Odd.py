n = int(input())

evenSum= oddSum= 0
while n > 0:
    digit= n % 10
    
    if digit & 1:
        oddSum += digit
    else:
        evenSum += digit

    n //= 10 

print(f'{evenSum} {oddSum}')

