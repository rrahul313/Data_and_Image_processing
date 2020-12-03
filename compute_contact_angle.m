clc;

clear all;
A = load('X_2.7_isoA.txt');
B = load('X_2.7_isoB.txt');

intercept_high = 99;
intercept_low = 97;

sympref('FloatingPointOutput',true)
syms XA XB X1A X1B;

x1 = A(:,1);
y1 = A(:,2);
x2 = B(:,1);
y2 = B(:,2);

indices1 = find(x1>98.2 | x1 < 90);
x1(indices1) = NaN;
indices2 = find(x2<98.6 | x2>106.8);
x2(indices2) = NaN;
A1 = [x1 y1];
B1 = [x2 y2];

A1(any(isnan(A1), 2), :) = [];
B1(any(isnan(B1), 2), :) = [];

x1 = A1(:,1);
y1 = A1(:,2);
x2 = B1(:,1);
y2 = B1(:,2);

fA = fit(x1,y1,'poly5');
fB = fit(x2,y2,'poly5');
%[X0,Y0,I,J] = intersections(x1,y1,x2,y2,robust);
%str2func(['f(x) = ' formula(fA)]);

pA = coeffvalues(fA);
pB = coeffvalues(fB);

eqA = vpa(poly2sym(pA,XA));
eqB = vpa(poly2sym(pB,XB));

p_diff = pA - pB;
r_diff = roots(p_diff);
roots_all = r_diff;
mask = find(r_diff<intercept_low | r_diff>intercept_high);
r_diff(mask) = [];
mask = find(imag(r_diff));
r_diff(mask) = [];


x_intercept = r_diff(1,1);
y_intercept = double(subs(eqA,XA,x_intercept));
%y_intercept = pA(1,1)*x_intercept^4 + pA(1,2)*x_intercept^3 + pA(1,3)*x_intercept^2 + pA(1,4)*x_intercept + pA(1,5); 
p1A = polyder(pA);
p1B = polyder(pB);

eq1A = poly2sym(p1A,X1A);
eq1B = poly2sym(p1B,X1B);

mA = subs(eq1A,X1A,x_intercept);
mB = subs(eq1B,X1B,x_intercept);
m1A = double(mA);
m1B = double(mB);
%mA = p1A(1,1)*x_intercept^3 + p1A(1,2)*x_intercept^2 + p1A(1,3)*x_intercept + p1A(1,4); 
%mB = p1B(1,1)*x_intercept^3 + p1B(1,2)*x_intercept^2 + p1B(1,3)*x_intercept + p1B(1,4);
lineA = [m1A (-m1A*x_intercept+y_intercept)];
lineB = [m1B (-m1B*x_intercept+y_intercept)];

theta = atand((m1B - m1A)/(1 + m1A*m1B))

hold on
plot(x1,y1,'--gs','LineWidth',2,'MarkerSize',10,'MarkerEdgeColor','g','MarkerFaceColor',[0.5,0.5,0.5])

plot(x2,y2,'--gs','LineWidth',2,'MarkerSize',10,'MarkerEdgeColor','b','MarkerFaceColor',[0.5,0.5,0.5])

t = linspace(x_intercept-10,x_intercept+10,3);  %adjust as needed
plot(t, polyval(lineA, t),'LineWidth',2)  % where a is coefficients of a polynomial
plot(t, polyval(lineB, t),'LineWidth',2)  % where a is coefficients of a polynomial

axis([x_intercept-7 x_intercept+7 y_intercept-7 y_intercept+7]);
hold off
%axis([90 110 114 134])
%x = linspace(0,100,100);

%plot(A)
%plot(x1,y1,'o',x,fnval(pp_A,x),'-')


