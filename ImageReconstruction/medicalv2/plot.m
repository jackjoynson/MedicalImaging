

filename = uigetfile('.csv')
M = csvread(filename)

figure
surf(M)
shading interp
xlabel('x')
ylabel('y')

