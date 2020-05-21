def img_show(img):
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()

(x_train, t_train),(x_test, t_test) = \
    load_mnist 

image = x_train[0]
label = t_train[0]