# Simulazione-Modello-SEIRD
Simulazione di un'epidemia di Covid 19 in una città immaginaria
Il programma è stato realizzato applicando il modello SEIRD ad una città artificiale, considerando parametri validi a descrivere la diffusione del virus Covid-19, senza alcuna limitazione alla libertà di spostamento e senza considerare protezioni personali come la presenza di mascherine.\\
La simulazione è stata implementata su un file Simulazione.c, mentre tutte le funzioni utilizzate sono state inserite in un header file Funzioni.h e implementate in Funzioni.c.
Sono poi presenti tre classi:
- Organize, è una classe Singleton che permette di istanziare i vari vettori utilizzati durante la simulazione, come il vettore di popolazione e degli edifici della città, in modo che vengano istanziati una volta sola.
- Persona, una classe che definisce le caratteristiche della persona.
- Edificio, una classe che definisce le caratteristiche dell'edificio.

Per lanciare la simulazione bisogna dunque utilizzare i seguenti comandi:

.L Persona.c++\
.L Edificio.c++\
.L Organize.c++\
.L Funzioni.c++\
.L Simulazione.c++\
Simulazione(InfectedPopulation, days)

InfectPopulation corrisponde al numero di infetti e days al numero di giorni su cui si sviluppa la simulazione.\
Il numero di persone create è inizializzato dal programma stesso nell'header file Organize.h e può essere dell'ordine di $10^{3}-10^{4}$, con un minimo di 1000.\
Nel corso della simulazione le persone decidono dove spostarsi e a fine giornata vengono raccolti i dati riguardanti la variazione degli stati in vettori utilizzati per incrementare i vari istogrammi distinti per età e stato.\
Gli istogrammi sono stati salvati in un file che viene letto attraverso la macro HistsSEIRD.C con la funzione omonima.

.L HistsSEIRD.c++\
HistsSEIRD()

La classe Persona è caratterizzata da otto variabili:

- fID, intero che corrisponde all'identità della persona.
- fStatus, intero che corrisponde allo stato di salute della persona, in particolare S=0, E=1, I=2, R=3, D=4.
- fHome\_id, intero che corrisponde al numero civico della casa.
- fWork\_id, intero che corrisponde al numero civico del luogo di lavoro o di scuola.
- fOrder, intero corrispondente all'ordine delle persone all'interno degli edifici di lavoro e scuola, utile per l'implementazione del movimento.
- fAge, intero corrispondente all'età della persona: Bambino=1, Giovane=2, Adulto=3, Anziano=4. I bambini hanno età compresa tra 0 e 18 anni, i giovani tra 18 e 30, gli adulti tra 30 e 70 e infine gli anziani con età maggiore di 70 anni.
- fLocation, intero corrispondente al civico dell'edificio in cui si trova la persona.
- fLocType, intero che corrisponde al tipo di edificio in cui si trova la persona: Casa=0, Scuola=1; Lavoro=2; Supermercato=3; Ristorante=4; Chiesa=5; Parco=6; Ospedale=7, Cimitero=8;

Oltre a queste variabili sono state implementate due funzioni utili per il movimento all'interno della città: ChangeBuildingMorning e ChangeBuildingAfternoon che permettono alla persona di scegliere in quale edificio andare con diverse probabilità. Le probabilità sono state scelte arbitrariamente secondo le abitudini delle varie fasce d'età e allo stato di salute.\
Per gli spostamenti della mattina le persone Susceptible, Recovered o Exposed, che non presentano sintomi, si spostano con la stessa probabilità in un luogo di lavoro, ufficio o scuola, in cui rimangono dalle 8 alle 14. Gli anziani invece si possono spostare in chiesa, al parco o rimanere in casa.\
In particolare non è stata considerata una differenza tra scuola e università, perciò i giovani e i bambini convoglieranno alle scuole.\
Per quanto riguarda le persone infette gli spostamenti variano leggermente, sarà maggiore la probabilità di rimanere a casa.\

Al pomeriggio le persone tendono a dirigersi verso luoghi di svago come il parco e il ristorante, cambiando luogo più spesso rispetto alla mattina, perciò nella simulazione dalle 14 alle 20 le persone cambiano luogo ogni due ore.\

Un'altra funzione utile allo spostamento è initializeLocation che inizializza il numero civico al primo di ogni tipo di edificio, una volta pieno il numero civico viene aumentato di uno con la funzione ChangeLocation, passando così all'edificio successivo, finchè non ne viene trovato uno libero.\
Questo non si applica alle persone che si dirigono a casa o al lavoro/scuola, infatti in questi tre casi le persone hanno posto ed edificio assegnato.\
Infine Backhome permette alla persona di tornare alla propria abitazione.\
La classe Edificio ha quattro variabili:
- fIDEdif, numero civico dell'edificio.
- fTypeEdif, intero corrispondente al tipo di edificio come indicato in fLocType della persona.
- fNumMax, numero massimo di persone permesso all'interno di un edificio.
- fCounter, contatore del numero di persone all'interno dell'edificio.

Il numero di edifici è definito nella creazione della città in funzione della popolazione.\
Tra le funzioni riveste particolare importanza AddToList che permette di incrementare il contatore dell'edificio. Esiste anche una funzione omonima in Funzioni.c che permette di riempire dei vettori, che corrispondono a tutti gli edifici dello stesso tipo, con gli ID delle persone.\
La simulazione consiste nella creazione della città e della popolazione, l'implementazione del movimento delle persone e il ricalcolo degli stati valutati in base a parametri medi, caratteristici del Covid-19, ricavati dal paper di riferimento$^{[1]}$.\
Come si vede in Figura 1 ogni persona ha una certa Probabilità di cambiare stato e queste vengono valutate con la funzione ChangeStatusPersons: Le persone Susceptible possono diventare Exposed e queste ultime a loro volta Infected, da qui si crea una dicotomia, una parte diventerà Ricovered e una parte Death. In particolare i parametri dipendono dalle età dunque abbiamo andamenti diversi delle curve in base alla persona.\
L'intervallo temporale entro il quale viene ricalcolata la probabilità di contagio corrisponde a 30 minuti.



[1] Management strategies in a SEIR-type model of COVID 19 community spread, Anca Rˇadulescu,
Cassandra Williams, Kieran Cavanagh (Pubblicato Online 04 Dicembre 2020)
