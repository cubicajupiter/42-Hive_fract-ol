
#The Mathematics Behind the Application
##Zoom
4.0 is initial MAGNITUDE of scale.
2.0 is initial OFFSET to CENTER of scale (half of magnitude).
1.3 is the constant factor of ZOOM.
W_WIDTH and HEIGHT will not change, so they remain constant factors of SCALE, together with magnitude, which is modified by zoom once applied.
with ZOOM, it should modify magnitude and offset.
SCALE and OFFSET are both subject to the same factor of zoom.
Zoom_in	divides	the magnitude, and zoom_out multiplies the magnitude by	a factor of zoom.

SO you divide f->magnitude by factor of ZOOM_IN.
SCALE is magnitude / pixels.
magn 4.0 / zoom 1.3 = magn 3.0769.. / pixels 1000 = 0.0030769 --> value of each increment on plane

Now you have two choices for counting the center offset factor:
A) divide initial offset by same ZOOM factor as magnitude, or
B) divide the new MAGNITUDE in half and use that

##Fractal Generation:

###generate_fractal:
The fractal generation function will loop W_WIDTH x W_HEIGHT times. Passing a pointer to a double that is initialized once is significantly more performant than declaring and initializing a double within the function for each of the one million iterations. That is why temp_zR is initialized in generate_fractal() and passed as a ptr to each gen_fractal_px() function. The same with the index which is passed as the macro constant INDEX 0.
Initializes the pixel coordinates x and y for the fractal. Sets the fractal's initial X scale as 4 divided by window width and sets its initial Y scale as the negative of 4 divided by window height. Because zoom modifies magnitude, which is a factor of scale, zoom affects scale.
The initial and maximum magnitude of 4 is based on that the mandelbrot set Cartesian Plane has an extent of 4 total on both sides of the origin counted together: a range from -2 to 2.
Y_scale is negative and x_scale is positive, because the cartesian plane y-axis decreases downward, while a window's pixel y-axis increases downward. 2.0 is added to the y_scale to "offset" the zero point into the middle of 4, keeping all pixel values under the halfway point negative, flipping pixel values above the halfway point into positives. Vice versa for x_scale.

###gen_mandel:
Z = Z^2 + C
has three loops nested inside one another. Outermost loop for looping y pixels, the next loop for looping x pixels, and the innermost for a number of iterations to plot the orbit for the set of coordinates x and y. The innermost loop contains the  Z = Z^2 + C  mandelbrot equation logic.

###gen_julia:
Like the mandelbrot, but C is a fixed value for all pixels, and the initial value of Z is set to the coordinates of the pixel being calculated. The fixed C value constant is set before iteration begins.
The key difference with mandelbrot is that mandel C assumes the value of the pixel, while julia C remains constant.

###gen_ship:
The burning ship fractal is slightly different from mandelbrot and julia, but utilizes the same variables Z and C since it uses complex numbers.
####Equation:
Z = (abs(Z_i) + abs(Z_R))^2 + C

####Implementation:
Real part (Z_R): x_n = x^2 - y^2 - C_x
Imag part (Z_i): y_n = (abs(x * y) * 2) + C_y

##Macros:

W_WIDTH: program window width in pixels
W_HEIGHT: program window height in pixels
MAX_ITERS: number of maximum iterations for plotting the orbit of one value of C
COLOR_ORBIT: hex value for a stable orbit (in MAX_ITERS number of iterations).
COLOR_1S: hex values for how many steps until divergence.



