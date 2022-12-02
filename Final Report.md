Skip to content
Search or jump to…
Pull requests
Issues
Codespaces
Marketplace
Explore
 
@vfleming1027 
AerE361
/
Final-Report
Private template
Code
Issues
Pull requests
Actions
Projects
Security
Insights
Final-Report/main.tex
@matgyver
matgyver Fix to outdated TOC
…
Latest commit a496137 on Nov 30, 2021
 History
 1 contributor
128 lines (97 sloc)  6.56 KB

\documentclass[12pt]{article}
\usepackage{tocloft}
\usepackage{natbib}
\usepackage{url}
\usepackage[utf8x]{inputenc}
\usepackage{amsmath}
\usepackage{graphicx}
\usepackage{verbatim}
\graphicspath{{images/}}
\usepackage{parskip}
\usepackage{fancyhdr}
\usepackage{vmargin}
\setmarginsrb{3 cm}{2.5 cm}{3 cm}{2.5 cm}{1 cm}{1.5 cm}{1 cm}{1.5 cm}
\usepackage{appendix}
\usepackage{listings} % For code importing
\usepackage{xcolor} % for setting colors
\input{arduinoLanguage.tex}  


\begin{document}
\title{Project Report}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\begin{titlepage}
	\centering
    \vspace*{0.5 cm}
    \includegraphics[scale = 0.11]{isu_seal.png}\\[1.0 cm]	% University Logo
    \textsc{\LARGE IOWA STATE UNIVERSITY}\\[2.0 cm]
    \textsc{\large AEROSPACE ENGINEERING DEPARTMENT}\\[0.2 cm]
    \textsc{\large Computational Techniques for Aerospace Design}\\[0.2 cm]
	\textsc{\Large AERE 361}\\[0.5 cm]				% Course Code
	\textsc{\Large Spring 2021}\\[0.5 cm]				% Course Code
	\textsc{\Large Final Project Report}\\[0.2 cm]
	\textsc{\Large TEAM NAME HERE}\\[0.2 cm]
	\rule{\linewidth}{0.2 mm} \\[0.4 cm]
	%{ \huge \bfseries \thetitle}\\
	
	
	\begin{minipage}{0.8\textwidth}
		
			\begin{flushleft} 
			\emph{Team Member Names :} \\
			Last Name, First Name\linebreak
			Last Name, First Name\linebreak
			Last Name, First Name\linebreak
			Last Name, First Name\linebreak
			Last Name, First Name\linebreak
			Last Name, First Name\linebreak
			
		\end{flushleft}
	\end{minipage}\\[2 cm]
	
	\vfill
	
\end{titlepage}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%\maketitle
\tableofcontents
\pagebreak
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\section{ABSTRACT}
This is your abstract.  It is a short summary of what your report will cover.  You should keep your abstract to 250 words or less.  Use this to ``hook in'' your reader.

\section{INTRODUCTION}
The introduction is where you will introduce your group and your project. List out the team members (optionally include a picture) and what their role is. Briefly introduce your project, what it does and why. A minimum of 2 paragraphs. Introduction is worth 5 points.

\section{FEATURES}
The features section is where you will outline the final list of features that your device ended up with. This should not be a copy from proposal and I expect that some minor changes may have happened. If you did need to make a change, include what those changes were and why. You can do an itemized list of your features, but you must have a supporting paragraph or two that goes into further detail. This section is worth 5 points.


\section{PROBLEM STATEMENT}
Your problem statement is stating what the problem(s) that you are attempting to solve. Again, this should not be a copy and paste from your proposal. State the problem and why you are solving it. This should be backed up with some light research. You may use the same references from your proposal, but if you done some more research since then, include additional citations as well. This section is worth 10 points.

\section{PROBLEM SOLUTION}
Here, you go into detail what your solution to the problem is.  I expect that this will have several subsections and you should breakout each area.  You should include any graphics and pictures as relevant as well and reference them like Figure \ref{fig:cpx}.
\begin{figure}[!t]
\centering
\includegraphics[width=4.5in]{cpx01.jpg}
\caption{This is the circuit playground express}
\label{fig:cpx}
\end{figure}

Again, cite any sources that you have.  If you took snippets of code or found a paper that discusses on how to do something, then you need to cite it. The same if you got inspiration for code from a source, cite that as well. For this final project report, I am expecting at least 3 sources cited.  One will probably be what you had in your problem statement from your proposal.  

Your problem solution is one of the largest things we look at. I am looking for the following items:

\begin{itemize}
    \item How did you come up with your solution
    \item How did you test or verify your solution
    \item Do you think this was a good solution?
    \item Show as much as you can of the solution in action (pictures and/or data)
\end{itemize}

For this reason, this section has the most points at 25 points

\section{STATUS}
Here, you need to honestly assess what the status of the project is.  If successful, state that it was successful and all the goals that it achieved (your goals are from your project proposal).  If not successful, state what was completed, what was not completed and state what happened. This part is worth 5 points

\subsection{Lessons Learned}
Here, put any lessons learned from this project.  This may also relate to some of the items that you did not accomplish with this project. If you did not accomplish something, why? What might you do differently? I am also looking for what the group learned through this process. The obvious answer is ``programming'', but I am looking beyond that. Tell me what other skills you think that you learned or that you improved up working on the project. These can include ``soft'' skills like teamwork, communication, leadership, etc. This section is worth 10 points

\section{RESULTS}

Put all results here.  If you collected data, explain and show at least some analysis on the data you collected.  If no data is collected, you should have collected reactions from others using your device and put that feedback here.  Any graphs you generated should be here as well.

You must include a copy of your source code in the appendix.  There is an example of this below.  Also, include the link to your GitHub repository.  You can use the \verb=\url=  command like this \url{https://github.com/AerE-361-FinalProject/Project-Report-AerE-361}. Make sure you reference where the code is located as well as any other data. This section is worth 10 points. 


\section{FUTURE WORK}
Your future work includes what your team would continue to improve on and change if you had more time.  This could be expanding additional features or fixing something that you couldn't figure out.  It helps to explain at least a little on what you would plan to do to improve your product. This section is worth 5 points.

\section{CONCLUSION}
Finally, wrap up your report. Although there is no points here, it is expected.

\newpage

\bibliographystyle{plain}
\bibliography{ref}
\newpage
% you need to have at least your code in your appendix
\appendix

\section{SOURCE CODE}
Source Code
\lstinputlisting[language=Arduino]{src/demo.ino}
\end{document}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Final-Report/main.tex at main · AerE361/Final-Report
