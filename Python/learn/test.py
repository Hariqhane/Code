import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif']=['KaiTi']  # 使用楷体显示中文
plt.rcParams['axes.unicode_minus'] = False  # 解决坐标轴负号显示问题

# Step 1: Read Antenna Data
dtype = {
    'names': ('name', 'x', 'y'),
    'formats': ('U10', 'f8', 'f8')
}
# 读取天线数据
antenna_data = np.loadtxt('D:\\Desktop\\meerKAT.txt', dtype=dtype, usecols=(0, 1, 2))
x_coords = antenna_data['x']
y_coords = antenna_data['y']
z_coords = np.zeros_like(x_coords)  # 假设天线在同一平面上，Z坐标为0

# Step 2: Compute Baseline Vectors
num_antennas = len(x_coords)
baseline_x = []
baseline_y = []
baseline_z = []

for i in range(num_antennas):
    for j in range(i+1, num_antennas):
        delta_x = x_coords[j] - x_coords[i]
        delta_y = y_coords[j] - y_coords[i]
        delta_z = z_coords[j] - z_coords[i]
        baseline_x.append(delta_x)
        baseline_y.append(delta_y)
        baseline_z.append(delta_z)

baseline_x = np.array(baseline_x)
baseline_y = np.array(baseline_y)
baseline_z = np.array(baseline_z)

# Step 3: Define the compute_uv Function
def compute_uv(baseline_x, baseline_y, baseline_z, wavelength, H_angle=0, declination=0):
    # 将角度转换为弧度
    H = np.deg2rad(H_angle)
    delta = np.deg2rad(declination)
    
    # Compute u and v
    u = (baseline_x * np.sin(H) + baseline_y * np.cos(H)) / wavelength
    v = (-baseline_x * np.sin(delta) * np.cos(H) + baseline_y * np.sin(delta) * np.sin(H) + baseline_z * np.cos(delta)) / wavelength
    
    return u, v

# Step 4: Set Up Observation Parameters
observations = [
    {'frequency': 1e9, 'H_angle': 0, 'declination': -30, 'title': '天顶, 1 GHz'},  # 假设望远镜纬度为-30°
    {'frequency': 1e9, 'H_angle': -1, 'declination': -30, 'title': '15° , 1 GHz'},
    {'frequency': 5e8, 'H_angle': 0, 'declination': -30, 'title': '天顶, 500 MHz'},
    {'frequency': 5e8, 'H_angle': -1, 'declination': -30, 'title': '15° , 500 MHz'},
]

# Step 5: Create a 2x2 Grid of Subplots
fig, axes = plt.subplots(2, 2, figsize=(12, 10))
axes = axes.flatten()

# Step 6: Compute u-v Coordinates and Plot
for idx, obs in enumerate(observations):
    frequency = obs['frequency']
    wavelength = 3e8 / frequency  # Speed of light divided by frequency
    H_angle = obs['H_angle']  # 时角
    declination = obs['declination']  # 赤纬
    title = obs['title']

    # Compute u and v
    u, v = compute_uv(baseline_x, baseline_y, baseline_z, wavelength, H_angle, declination)

    # Plot u-v coverage
    ax = axes[idx]
    ax.scatter(u, v, s=7, color='blue', label='(u, v)')
    # ax.scatter(-u, -v, s=1, color='red', label='(-u, -v)')
    ax.set_title(title)
    ax.set_xlabel('u (wavelengths)')
    ax.set_ylabel('v (wavelengths)')
    ax.axis('equal')
    # ax.set_xlim(-20000, 20000)  # 调整u轴范围
    # ax.set_ylim(-20000, 20000)  # 调整v轴范围
    ax.grid(True)
    # ax.legend()

# Step 7: Adjust Layout and Show the Plot
plt.tight_layout()
plt.show()
