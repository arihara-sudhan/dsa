def karatsuba_simple(x, y):
    if x < 10 or y < 10:
        return x * y
    n = max(len(str(x)), len(str(y)))
    m = n // 2          
    B = 10 ** m         
    a, b = divmod(x, B)
    c, d = divmod(y, B)
    p1 = karatsuba_simple(a, c)
    p2 = karatsuba_simple(b, d)
    p3 = karatsuba_simple(a + b, c + d)
    mid = p3 - p1 - p2
    return (p1 * B * B) + (mid * B) + p2

print(karatsuba_simple(234, 345))
print(karatsuba_simple(23, 45))    # → 1035
