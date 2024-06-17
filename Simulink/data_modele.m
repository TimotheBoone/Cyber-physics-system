tau = 0.02;
k = 50;

a = -1/tau;
b = k/tau;

ar = [a 0; -1 0];
br = [b;0];

% Calcul retour d'état à la main pour les pôles -50 et -60
% k1 = 3000/2500;
% k2 = (50-110)/2500;

% Calcul retour d'état automatisé
vp_a = eig(a);
triple_vp_a = 3*vp_a;
vp_desirees = [vp_a triple_vp_a];
K = place(ar, br, vp_desirees);
k1 = K(1, 2);
k2 = K(1, 1);

% Calcul paramètres observateur
Ao = [a 0;1 0];
Bo = [b;0];
Co = [0 1];
vpo_desirees = [3*vp_a 3.3*vp_a];

Lt = place(transpose(Ao), transpose(Co), vpo_desirees);
L = transpose(Lt);

% Calcul paramètres observateur étendu
Aobis = [a 0 b;1 0 0;0 0 0];
Bobis = [b;0;0];
Cobis = [0 1 0];
vpobis_desirees = [1.5*vp_a 1.6*vp_a 1.7*vp_a];

Lbist = place(transpose(Aobis), transpose(Cobis), vpobis_desirees);
Lbis = transpose(Lbist);

% Anti wind-up
Kb = 50;