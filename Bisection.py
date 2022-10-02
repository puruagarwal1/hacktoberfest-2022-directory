########################################
# BISECTION METHOD FOR SOLVING EQUATIONS
########################################

'''The aim of this porgram is to solve equation by bisection method in given interval.
    As the equatoin Identifier was not made yet so please type the
    equation before execution of code in a manner that python can
    understand it easily.'''

def function(interval):
    #identifying the interval.
    numbers = interval[1:-1].split(",")
    low_limit_val = f(float(numbers[0]))
    upper_limit_val = f(float(numbers[1]))
    if interval[0] == "[":
        low_limit = "inclusive"
        if low_limit_val == 0:
            print("Root of this equation is:",float(numbers[0]))
            return 0
    else:   low_limit = "exclusive"
    if interval[-1] == "]":
        upper_limit = "inclusive"
        if upper_limit_val == 0:
            print("Root of this equation is:",float(numbers[1]))
            return 0
    else:   upper_limit = "exclusive"

    # Bisection method
    if low_limit_val*upper_limit_val < 0:
        a = float(numbers[0])
        b = float(numbers[1])
        limit = (a+b)/2
        ans = f(limit)
        while (str(ans)[:4] != "0.00"):  #checking for two decimal places only
            if ans < 0:
                a = limit
            elif ans > 0:
                b = limit
            limit = (a+b)/2
            ans = f(limit)
        if str(ans)[:4] == "0.00":
            print("Root of this equation is:",limit)
    else:   print("No root exists in this interval")
    

def f(x):
    return x**3 - x -1 #Edit this equation here if you want to try this for other equations.



######main_function#####
interval = input("Enter the interval:") #format [3,5] or (3,5)
function(interval)
