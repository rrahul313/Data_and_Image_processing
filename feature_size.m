clc;
close all;

clear all;
N_last=299;

    
comp = zeros(300);
comp1 = zeros(300);
comp2 = zeros(300);
%filename = sprintf('slice%d.txt', j);
fileID = fopen("33-33-33/0.31_A.txt", 'r');
comp = fscanf(fileID,'%f %f', [300 298]);
   
fclose(fileID);

comp1 = imbinarize(comp,0.55);
comp2 = imcomplement(comp1);
%im = imagesc(comp2);

cc = bwconncomp(comp1,8);
n = cc.NumObjects;

Area =  zeros(n,1);
Perimeter = zeros(n,1);
%MajorAxis = zeros(n,1);
%MinorAxis = zeros(n,1);
F_ratio = zeros(n,1);
k = regionprops(comp1, 'Area', 'Perimeter');

%fname=sprintf('time_%d.vtk',istep);
out =fopen("feature_dataA.dat",'w');

for i = 1:n
    Area(i) = k(i).Area;
    Perimeter(i) = k(i).Perimeter;
    a = Area(i,1);
    b = Perimeter(i,1);
F_ratio(i) = a/b;

if (b==0)
    F_ratio(i) = 0;
end
end

A = sort(Area);
B = sort(Perimeter);
C = sort(F_ratio);

for j = 1:n
    x(j,1) = j;
fprintf(out,'%d\t%5.3e\t%5.3e\t%5.3e\n', j, A(j,1), B(j,1), C(j,1));
end
fclose(out);

sA = subplot(3,1,1);
scatter(sA,x,A,'filled')

sB = subplot(3,1,2);
scatter(sB,x,B,'filled')

sC = subplot(3,1,3);
scatter(sC,x,C,'filled')


subplot(3,1,1);
fitA = histfit(A,5,'kernel');
%title('Area')
xlabel('Feature Area')


% hold on
% x_pdf = 0:300:1300;
% y = 500*normpdf(x_pdf);
% mu = 5;
% sigma = 2;
% f = exp(-(y-mu).^2./(2*sigma^2))./(sigma*sqrt(2*pi));
% plot(x_pdf,y,'LineWidth',1.5)

subplot(3,1,2);
fitB = histfit(B,5,'kernel');
%title('Perimeter')
xlabel('Feature Perimeter')

subplot(3,1,3);
fitC = histfit(C,5,'kernel')
%title('A/P ratio')
xlabel('A/P ratio')

%
% A(j,1) = j;
% A(j,2) = mean(Area);
% P(j,1) = j;
% P(j,2) = mean(Perimeter);
% F(j,1) = j;
% F(j,2) = mean(F_ratio);
% 
% S_area(j,1) = j;
% S_area(j,2) = std(Area,1);
% S_perimeter(j,1) = j;
% S_perimeter(j,2) = std(Perimeter,1);
% S_ratio(j,1) = j;
% S_ratio(j,2) = std(F_ratio,1);
% 
% save('area_60.txt', 'A', '-ASCII');
% save('perimeter_60.txt', 'P', '-ASCII');
%save('S_area_81.txt', 'S_area', '-ASCII');
%save('S_perimeter_81.txt', 'S_perimeter', '-ASCII');

%graindata(3,1) = mean(MajorAxis);
%graindata(4,1) = mean(MinorAxis);
%imshow(im);