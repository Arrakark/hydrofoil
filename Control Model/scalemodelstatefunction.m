function [z, d] = scalemodelstatefunction(x,u,T)
% This is the state function for a scale model of the jetski
% 	Parameters and functions that calculate lift, moments, ect, come first, then the actual state equations of motion
%   See https://www.mathworks.com/help/mpc/ug/specify-prediction-model-for-nonlinear-mpc.html

% Constants
km = [
    0.059837167468009, 0.123089337540016, 0.007000428614195, 0.000400633385127, -0.842918949631673, -0.002064628688432, -1.71016334932943, 0.000635883467746, -0.148953182710779, 0.001990896417202, -0.264547718230347, 0.56190324477378, 1.16592382999908, -0.014620870988362, 0.680029579778176, 1.12900797330793, 2.72092938535652, -0.004681332476735, 21.8442180656307, -0.21458816452553, -2.57798661517169;
    0.059837167468009, 0.123089337540016, 0.007000428614195, 0.000400633385127, -0.842918949631673, 0.002064628688432, -1.71016334932943, -0.000635883467746, 0.148953182710779, -0.001990896417202, -0.264547718230347, -0.56190324477378, -1.16592382999908, -0.014620870988362, 0.680029579778176, 1.12900797330793, 2.72092938535652, 0.004681332476735, 21.8442180656307, 0.21458816452553, 2.57798661517169;
    0.051044640159881, 0.102953339828898, 0.0110918273562955, 0.00035586071580164, -0.929387562423644, -0.005389836299135, 1.16490114093911, -0.029421329449385, -0.335773463802011, 0.005483455029074, -0.190310740935575, 0.657705383330711, 1.44030027410489, -0.017328907635805, -0.639350193116264, -0.924134135496948, -2.28583298385006, -0.002358398901614, 18.5546825201298, -0.091448204338672, -0.887493289646403;  
    0.051044640159881, 0.102953339828898, 0.0110918273562955, 0.00035586071580164, -0.929387562423644, 0.005389836299135, 1.16490114093911, 0.029421329449385, 0.335773463802011, -0.005483455029074, -0.190310740935575, -0.657705383330711, -1.44030027410489, -0.017328907635805, -0.639350193116264, -0.924134135496948, -2.28583298385006, 0.002358398901614, 18.5546825201298, 0.091448204338672, 0.887493289646403;
];

A = [0.075 0.075 0.101  0.101]; %wing areas in m^2, 1) front_left 2) front_right 3) rear_left 4) rear_right
Jxx = 10000;
Jyy = 10000;
Jzz = 10000;
a = 9.81;
dt = 1; % distance from cg to thrust vector
m = 298; % total mass of craft

% calculating wing forces and moments
X = 0;
Y = 0;
Z = 0;

L = 0;
M = 0;
N = 0;

Vt2 = norm(x(4:6))^2;
qbar = 0.5 * 997 * Vt2;
beta = atan(x(5)/x(4));
alpha = rad2deg(atan(x(6)/x(4))) + rad2deg(x(7));

for k = 1:4
    % for each wing, calculate the CD, CL, lift, drag, X, Y, Z, L, M, and N, and
    % sum them
    CL = km(k,1) * (alpha + u(k)) + km(k,2);
    CD = km(k,3) + km(k,4) * (alpha + u(k) - km(k,5)) ^ 2;
    Fdrag = qbar * A(k) * CD;
    Flift = qbar * A(k) * CL;
    Xc = Flift * sind(alpha) - Fdrag * cosd(alpha);
    Yc = Vt2 * (km(k,6) * (alpha + u(k) - km(k,7)) + km(k,8) * (alpha + u(k) - km(k,7)) ^ 2 + km(k,9));
    Zc = - Fdrag * sind(alpha) - Flift * cosd(alpha);
    Lc = (km(k,10) * (alpha + u(k) - km(k,11)) + km(k,12) * (alpha + u(k) - km(k,11)) ^ 2 + km(k,13)) * Vt2 * cos(beta);
    Mc = ((km(k,14) * (alpha + u(k) - km(k,15)) + km(k,16) * (alpha + u(k) - km(k,15)) ^ 2 + km(k,17)) * Vt2) * cos(beta) + T * dt;
    Nc = (km(k,18) * (alpha + u(k) - km(k,19)) + km(k,20) * (alpha + u(k) - km(k,19)) ^ 2 + km(k,21)) * Vt2 * cos(2 * beta);
    
    X = X + Xc;
    Y = Y + Yc;
    Z = Z + Zc;
    L = L + Lc;
    M = M + Mc;
    N = N + Nc;
end

% hull parameters
if x(3) > 0
    Z = Z + x(3) * -10000;
end

X = X + T;

% Define rotation matrixes
R_body_to_nav = [cosd(x(9))*cosd(x(7)) cosd(x(9))*sind(x(8))*sind(x(7))-cosd(x(8))*sind(x(9)) sind(x(8))*sind(x(9))+cosd(x(8))*cosd(x(9))*sind(x(7)); cosd(x(7))*sind(x(9)) cosd(x(8))*cosd(x(9))+sind(x(8))*sind(x(9))*sind(x(7)) cosd(x(8))*sind(x(9))*sind(x(7))-cosd(x(9))*sind(x(8)); -sind(x(7)) cosd(x(7))*sind(x(8)) cosd(x(8))*cosd(x(7))];

% each state variable definition below is the derivitive of said variable
% in other words, z(1) = d/dt * u
z = zeros(12,1);
d = zeros(6,1);
z(1:3) = R_body_to_nav * x(4:6);
z(4) = (1 / m) * (X - m * a * sind(x(7)) + m * (x(5) * x(12) - x(11) * x(6)));
z(5) = (1 / m) * (Y + m * a * sind(x(8)) * cosd(x(7)) + m * (x(10) * x(6) - x(12) *  x(4)));
z(6) = (1 / m) * (Z + m * a * cosd(x(8)) * cosd(x(7)) + m * (x(11) * x(4) - x(10) *  x(5)));
z(7) = x(11) * cosd(x(8)) - x(12) * sind(x(8));
z(8) = x(10) + x(11) * sind(x(8)) * tand(x(7)) + x(12) * cosd(x(8)) * tand(x(7));
z(9) = x(11) * sind(x(7)) / cosd(x(7)) + x(12) * cosd(x(8)) / cosd(x(7));
z(10) = (1 / Jxx) * (L + (Jyy - Jzz) * x(11) * x(12));
z(11) = (1 / Jyy) * (M + (Jzz - Jxx) * x(10) * x(12));
z(12) = (1 / Jzz) * (N + (Jxx - Jyy) * x(10) * x(11));

d(1) = X;
d(2) = Y;
d(3) = Z;
d(4) = L;
d(5) = M;
d(6) = N;
end

