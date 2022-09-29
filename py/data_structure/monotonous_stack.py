arr = [2, 5, 3, 6, 8, 4, 7, 1]

# 寻找下一个更大元素,用单调递减(从栈底到栈顶递减)的栈
st = []
for num in reversed(arr):
    while st and num >= st[-1]:
        st.pop()
    st.append(num)
    print(st)
