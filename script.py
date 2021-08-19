import matplotlib.image as mpimg 
import matplotlib.pyplot as plt 
  
# Read Images 
img = mpimg.imread('pil_text.png') 
# Output Images 
plt.imshow(img)
plt.waitforbuttonpress()

