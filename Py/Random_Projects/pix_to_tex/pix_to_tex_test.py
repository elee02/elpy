from PIL import Image
from pix2tex.cli import LatexOCR

img = Image.open('path/to/image.png')
model = LatexOCR()
print(model(img))