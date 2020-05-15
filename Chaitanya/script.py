import matplotlib.image as mpimg 
import matplotlib.pyplot as plt 
  
# Read Images 
img = mpimg.imread('/Users/chaitanya/pil_text.png') 
# Output Images 
#plt.imshow(img)
#fig, ax = plt.subplots()
#ax.imshow(img)
#ax.spines['top'].set_visible(False)
#ax.spines['left'].set_visible(False)
ax.spines['bottom'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.set_xticks([])
ax.set_yticks([])
plt.show()
plt.waitforbuttonpress()
