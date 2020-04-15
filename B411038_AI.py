c#1번
print("Hello World")
#2번
name = "youngsu"
print(f"name = {name}")
#3번
numbers = ['one','two','three','four','five']
copy_number1 = numbers[:]
copy_number2 = numbers
print("copy_numbers1 :",copy_number1)
print("copy_numbers2 :",copy_number2)
numbers.extend(['six'])
print(numbers)
print("copy_numbers1 :",copy_number1)
print("copy_numbers2 :",copy_number2)
print(numbers[:3])
print(numbers[1:4])
print(numbers[3:])

