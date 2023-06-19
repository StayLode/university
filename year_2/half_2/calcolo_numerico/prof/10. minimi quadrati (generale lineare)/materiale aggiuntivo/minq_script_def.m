clear variables
close all

%%%%%%%%%%%%%%%%%%%%%%
% INTERFACCIA UTENTE %
%%%%%%%%%%%%%%%%%%%%%%

% (1) MODALITA
% modalità test: dati generati automaticamente
% modalità analisi: dati letti da file: (legge il file x_minq.txt per le ascisse 
%                                        e il file y_minq.txt per le ordinate)
% UTILIZZO: commentare quello che non si vuole usare dei due.
mod = "test";
%mod = "analisi";


% (2) PARAMETRI MODELLO / FUNZIONI DI BASE
% sia g(x) la "funzione risultato" (dell'algoritmo dei minimi quadrati)
% sia alpha = (alpha(1), alpha(2), ... , alpha(n)) il vettore dei parametri del modello
% siano f1(x), f2(x), ..., fn(x) le funzioni di base del modello
% g(x) = alpha(1) * f1(x) + alpha(2) * f2(x) + ... + alpha(n) * fn(x)
% n_param: ci sono tanti parametri quante funzioni di base

n_param = 2; % ATTENZIONE (vedi sotto)
% le funzioni di base sono definite mediante il vettore (di celle) f
f = cell(n_param,1); % struttura per costruire un vettore di funzioni
%
% per configurare le funzioni di base si agisce di seguito:
% si possono aggiungere nuove funzioni manualmente f{j} = @(t) 'legge'
% dove:
% j deve essere il cosecutivo dell'ultima funzione presente, 
% @(t) specifica qual'è la variabile e 'legge' è la funzione che volte usare 
% (attenzione: x è un vettore e vale sempre la sintassi delle operazioni matlab)
%
% definizione delle funzioni (componenti del vettore f)
f{1} = @(t) t.^0;
f{2} = @(t) exp(-1*t);
%f{3} = @(t) exp(t);
% ATTENZIONE: n_param deve coincidere con il numero di funzione definite
%             commentare quelle superflue.
if(n_param ~= length(f))
    error("il numero di funzioni di base non coincide con il numero dei parametri");
end

% (3) finezza della stampa del grafico della funzione risultato
n_plot = 1000; % punti per la stampa del grafico della funzione risultato

% (4) salvataggio delle ascisse e ordinate che generano il grafico in un
% file .mat
save_result = true; % salva se true

% (5) specifiche aggiuntive MODALITA TEST
% nel caso si utilizzi la modalità test vanno specificate le seguenti
% quantità:
if(mod=="test")
    a = -2; % estermo sx intervallo dele ascisse dei dati
    b = 4; % estermo dx intervallo dele ascisse dei dati
    m = 100; % numero di dati
    equi_spaz = false; % se true i dati sono equispaziati in a,b altrimenti le ascisse sono random
    vol = 0.5; % amplificatore/riduttore del rumore 

    % NOTA. la funzione che genera le "ordinate esatte" è nel file
    % my_function.m

    % mette a true se volete generare un dataset salvando le x e le y (perturbate)
    % in due file di testo (x_autogen.txt, y_autogen.txt)
    % NOTA. se volete utilizzarle in seguito come input per la modalità
    % "analisi" ricordatevi di rinominare i file:
    % x_autogen.txt -> x_minq.txt
    % y_autogen.txt -> y_minq.txt
    save_data = true;
end

%%%%%%%%%%%%%%%%%%%%%%

if(mod=="test")
    % crea i dati senza rumore
    if(equi_spaz)
        x = linspace(a,b,m); % ascisse dati: m punti equispaziati in [a,b]
    else 
        x = rand(m,1) * (b-a) + a; % ascisse dati: m punti presi a caso in [a,b]
    end
    y = my_function(x); % ordinate: i valori esatti

    % "sporcare" i dati
    y = y + vol * randn(m,1); % aggiungo alle ordinate il rumore per simulare errori sperimentali
                              % il valore di vol regola "il peso" del rumore

    % salva i dati se richiesto:
    % deve salvare i contenuti delle variabili x e y in due distinti file
    % di testo.
    if(save_data)
        save("x_autogen.txt","x","-ascii");
        save("y_autogen.txt","y","-ascii");
    end

end

if(mod=="analisi")
    x = importdata("x_minq.txt"); % nome del file con le ascisse
    y = importdata("y_minq.txt"); % nome del file con le ordinate
    % NOTA. affinchè i dati siano caricati in un vettore colonna devono
    % essere salvati come un vettore colonna nel file.
    m = length(x);
    a = min(x);
    b = max(x);
end

% asacisse per il plot
x_plot = linspace(a, b, n_plot)'; % ascisse per la stampa del risultato

% regressione
alpha = my_minq(x,y,f,false);

% si valuta la funzione ottenuta con il metodo di minimi quadrati nelle
% ascisse contenute nel vettore x_plot e i valori ottenuti sono
% memorizzati nel vettore y_plot.
fij = zeros(n_plot, n_param);
% fij = f{j}( x_plot(i) ) la j-sima funzione di base valutata nella i-sima
% componente del vettore x_plot
for j=1:n_param
    fij(:,j) = f{j}(x_plot); 
end
y_plot = fij * alpha;


% stampa
figure
hold on
plot(x,y,'or'); %stamnpa dei dati
plot(x_plot,y_plot,'b'); % stampa del risultato

% stampa a schermo numeri interssanti

% il vettore dei coefficienti
msg1 = "alpha = [";
for i = 1 : n_param 
    msg1 = msg1 + num2str( alpha(i) );
    if(i<n_param) 
        msg1 = msg1 + " , ";
    else
        msg1 = msg1 + "] ";
    end
end
disp( msg1 );

% errore quadratico medio
M = zeros(length(x),n_param);
for i=1:n_param
    M(:,i) = f{i}(x);
end
y_ris = M * alpha;
er = y - y_ris;
er = sqrt( (er' * er) / length(x) );
disp("errore qudratico medio: " + num2str(er));

% se richiesto salva le ascisse e le ordinate realtive al plot del grafico
% della funzione risultato in un file .mat
if(save_result)
    Res = [ x_plot , y_plot ];
    save("x_y_result.mat","Res");
end

