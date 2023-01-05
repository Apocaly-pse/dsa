from PIL import Image
import numpy as np

# 读取图片
img = Image.open('image.png')

# 将图片转换为数组
arr = np.array(img)

# 统计每个颜色出现的次数
colors = {}
for row in arr:
    for pixel in row:
        if tuple(pixel) in colors:
            colors[tuple(pixel)] += 1
        else:
            colors[tuple(pixel)] = 1

# 按颜色数量从大到小排序
sorted_colors = sorted(colors.items(), key=lambda x: x[1], reverse=True)

# 创建一个新图片，用于保存发色图
new_img = Image.new('RGB', img.size, (255, 255, 255))

# 绘制发色图
for y in range(img.height):
    for x in range(img.width):
        for color, count in sorted_colors:
            if arr[y][x][0] == color[0] and arr[y][x][1] == color[1] and arr[y][x][2] == color[2]:
                new_img.putpixel((x, y), color)
                break

# 保存发色图
new_img.save('new_image.png')
