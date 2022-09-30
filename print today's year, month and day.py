# Python program to
# print today's year, month and day

# importing the date class datetime module
from datetime import date

# creating the date object of today's date
current_date = date.today() 

# printing the current date
print("Current date: ", current_date)

# extracting the current year, month and day
print("Current year:", current_date.year)
print("Current month:", current_date.month)
print("Current day:", current_date.day)
