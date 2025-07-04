%% Copyright 2005 Sibling_Dex
%
% This work may be distributed and/or modified under the
% conditions of the LaTeX Project Public License, either version 1.3
% of this license or (at your option) any later version.
% The latest version of this license is in
%   http://www.latex-project.org/lppl.txt
% and version 1.3 or later is part of all distributions of LaTeX
% version 2005/12/01 or later.
%
% This work has the LPPL maintenance status “maintained”.
% 
% The Current Maintainer of this work is Sibling_Dex.
%
% This work consists of the files dragonbane-supplement.cls

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{dragonbane-supplement}[2025 version]
%%========== ARTICLE =========%%
\DeclareOption{blackwhite}{\gdef\blackwhite\true}
\DeclareOption{onepage}{\gdef\onlyonepage\true}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{ctexrep}}
\ProcessOptions\relax
\LoadClass[10pt,a4paper,english]{ctexrep}
%%========= PACKAGES =========%%
\RequirePackage{multicol} 
\RequirePackage[hidelinks]{hyperref}
\RequirePackage{geometry}
\geometry{
    textwidth=17cm,
    top=2cm,
    headsep=5mm,
    bottom=2.5cm,
    footskip=2cm
}
\setlength{\columnsep}{2em}
\raggedbottom
%%========== FONTS ==========%%
\RequirePackage[english]{babel}
\RequirePackage[autostyle]{csquotes}
    \MakeOuterQuote{"}
\RequirePackage{fontspec,pifont,bbding}
    \setmainfont{Crimson Pro}
    \setsansfont{QTFrizQuad}
    \newfontfamily\tffamily{Colus.otf}[
        Path = ./fonts/,
        AutoFakeBold = 3,
    ]
    \gdef\titlefont{\tffamily\bfseries}
%%========== COLORS ==========%%
\RequirePackage[table,dvipsnames]{xcolor}
\definecolor{DemonGreen}{RGB}{34, 114, 98}
\definecolor{DragonRed}{RGB}{231, 47, 50}
\definecolor{InkBlack}{RGB}{35, 31, 32}
\definecolor{LightGreen}{RGB}{223, 235, 227}
\definecolor{BoneWhite}{RGB}{245, 242, 235}
\definecolor{ScrollBrown}{RGB}{85, 34, 0}
\definecolor{StainBrown}{RGB}{102, 85, 45}
\definecolor{Sand}{RGB}{232, 219, 191}
\colorlet{textlight}{white}
    \ifdefined\blackwhite
        \colorlet{title}{black}
        \colorlet{secret}{black}
        \colorlet{text}{black}
        \colorlet{accent}{black}
        \colorlet{page}{white}
        \colorlet{light}{lightgray!50}
        \colorlet{row}{lightgray!50}
    \else
        \colorlet{title}{DragonRed}
        \colorlet{secret}{DragonRed}
        \colorlet{text}{InkBlack}
        \colorlet{accent}{DemonGreen}
        \colorlet{page}{BoneWhite}
        \colorlet{light}{StainBrown}
        \colorlet{row}{ScrollBrown!10!Sand}
    \fi
\newcommand{\partcolor}[1]{
    \clearpage
    \ifdefined\blackwhite\else
        \colorlet{accent}{#1}
    \fi
}
%%======== TABLES ========%%
\RequirePackage{tabulary}
\RequirePackage{ragged2e}
    \tymax=\textwidth
    \def\arraystretch{1.5}
    \rowcolors{1}{row}{}
%%======== BACKGROUND ========%%
\RequirePackage{graphicx,pagecolor,background}
\RequirePackage[Export]{adjustbox}
    \pagecolor{page}
\ifdefined\blackwhite
    \backgroundsetup{
        contents = {}
    }
\else
    \backgroundsetup{
        scale = 1,
        angle = 0,
        opacity = 0.5,
        contents = {
            \includegraphics[height=\paperheight,width=\paperwidth]{img/parchment.jpg}
        }
    }
\fi
%% ======== COMMANDS ======== %%
\newcommand*\@NoIndentAfter{%
    \@ifnextchar\par{%
        \def\par{\everypar{\setbox\z@\lastbox\everypar{}}\@restorepar}%
    }{}
}
\newcommand*{\NoIndentAfterThis}{\@NoIndentAfter\par\par}
\newcommand*{\hrulefil}{\leavevmode\leaders\hrule height 0.7ex depth \dimexpr2pt-0.7ex\hfill\kern0pt}
\newcommand*{\bline}{\noalign{\hrule height 1pt}}
%%===== OLD ENVIRONMENTS =====%%
\RequirePackage{setspace,enumitem}

\newcommand\bolditem[1]{\item \textbf{#1}}
\newcommand\coloritem[2][accent]{{\color{#1}\item \textbf{#2}}}
\newcommand\secretitem[1]{{\color{secret}\item \textbf{\itshape#1}}}

\setlist[itemize]{noitemsep,topsep=0.5em,leftmargin=1.5em,label=\ding{70}}
\setlist[enumerate]{noitemsep,topsep=0.5em,leftmargin=1.5em}
\setlist[description]{font=\tffamily\bfseries,topsep=0.5em,itemsep=0.5em,leftmargin=0pt}

\AddToHook{env/itemize/after}{\NoIndentAfterThis}
\AddToHook{env/enumerate/after}{\NoIndentAfterThis}
\AddToHook{env/description/after}{\NoIndentAfterThis}
%% ==== NEW ENVIRONMENTS ==== %%
\renewenvironment{quote}%
    {\large\itshape\centering
    \list{}{\leftmargin=0.5em
        \rightmargin\leftmargin}
        \item\relax}%
    {\endlist\NoIndentAfterThis}
\newenvironment{segment}[1][]{
    \begin{multicols}{2}[
        \ifx\empty#1\empty\else\section{#1}\fi
    ]
}{
    \end{multicols}
}
\newenvironment{tablebox}[2][]{
    \begin{emptybox}[#1]{#2}
    \centering\small\sffamily
}{
    \end{emptybox}
}
\newenvironment{pagetable}[2][]{
    \onecolumn
    \begin{tablebox}[#1]{#2}
}{
    \end{tablebox}
    \twocolumn
}
%%==== TITLE ====%%
\providecommand{\subtitle}[1]{\gdef\@subtitle{#1}}
\providecommand{\credits}[1]{\gdef\@credits{#1}}
\providecommand{\version}[1]{\gdef\@version{#1}}
\gdef\@authorkey{AUTHOR}
\gdef\@creditskey{CREDITS}

\renewcommand*{\maketitle}{%
    \begin{titlepage}
        \begin{center}
            \vspace*{4cm}
            \color{title}\fontsize{60}{60}\titlefont\MakeUppercase\@title\par
            
            \vspace{4mm}
            \normalsize\hspace{-2.5mm}%
            \begin{tikzpicture}
                \draw[color = title,line width = 3pt] (0,0) -- (17,0);
                \pic[fill = title] at (0,0) {head};
                \pic[fill = title,scale=1.5] at (8.5,0) {tip};
                \pic[fill = title] at (17,0) {head};
            \end{tikzpicture}\par
            
            \ifdefined\@subtitle
                \vspace{4mm}
                \color{text}\fontsize{25}{25}\titlefont\@subtitle\par
            \fi
            \ifdefined\@version
                \vspace{4mm}
                \normalsize\normalfont Version~\@version\par
            \fi

            \normalsize\color{text}
            \vspace{8mm}
            \begin{minipage}{0.5\textwidth}\centering
                \titlefont \@authorkey:\par
                \normalfont\@author
                
                \vspace{4mm}
                \titlefont \@creditskey:\par
                \setlength{\parskip}{0.5em}\vspace{-0.5em}
                \normalfont\@credits
            \end{minipage}
    
            \vfill
            \ifdefined\blackwhite
                \includegraphics[width=0.5\linewidth]{img/Dragonbane-licenslogo-svart.png}
            \else
                \includegraphics[width=0.5\linewidth]{img/Dragonbane-license-logo-red.png}
            \fi
        \end{center}
    \end{titlepage}
}
%%==== PIKZ ====%%
\RequirePackage{tikz}
\usetikzlibrary{shapes.geometric}
\tikzset{
    pics/fourstar/.style ={
        code = {
            \fill (-.25,0) to[out=25,in=245] (0,.25) to[out=295,in=155] (.25,0) to[out=205,in=65] (0,-.25) to[out=115,in=335] cycle;
        },
    },
    pics/leftcap/.style ={
        code = {
            \fill (0.25,-.45) to[out=180,in=18] (0,-.5) to[in=-36,out=-242] (-.45,0) to[out=36,in=242] (0,.5) to[out=-18,in=180] (0.25,.45);
        },
    },
    pics/lefttip/.style ={
        code = {
            \fill (0.25,-.45) to[out=180,in=18] (0,-.5) to[in=0,out=-242] (-.9,0) to[out=0,in=242] (0,.5) to[out=-18,in=180] (0.25,.45);
        },
    },
    pics/leftspike/.style ={
        code = {
            \fill (.25,0) to[out=180,in=18] (0,-.05) to[in=-36,out=-242] (-.45,.45) to[out=36,in=270] (0,1.5);
        },
    },
    pics/downspike/.style ={
        code = {
            \fill (-1.7,.3) -- (1.7,.3) -- (1.5,0) to[out=180,in=50] (0,-.5) to[out=130,in=0] (-1.5,0) -- cycle;
        },
    },
    pics/upspike/.style ={
        code = {
            \fill (-1.7,-.3) -- (1.7,-.3) -- (1.5,0) to[out=180,in=330] (0,.2) to[out=210,in=0] (-1.5,0) -- cycle;
        },
    },
    pics/tip/.style ={
        code = {
            \fill (-0.5,0) to[out=0,in=135] (0,-.15) to[out=45,in=180] (0.5,0) to[out=180,in=-45] (0,.15) to[out=-135,in=0] cycle;
        },
    },
    pics/tipup/.style ={
        code = {
            \fill (-0.5,0) -- (-0.5,-0.1) -- (0.5,-0.1) -- (0.5,0) to[out=180,in=-45] (0,.15) to[out=-135,in=0] cycle;
        },
    },
    pics/head/.style ={
        code = {
            \fill (-.25,0) to[out=-20,in=135] (0,-.125) to[out=45,in=200] (.25,0) to[out=160,in=-45] (0,.125) to[out=-135,in=20] cycle;
        },
    },
}
%%==== BOXES ====%%
\RequirePackage[most]{tcolorbox}
\tcbset{
    enhanced,
    sharp corners,
    beforeafter skip = 2em,
    fontupper = \small\sffamily,
    fonttitle = \large\titlefont,
    coltitle = textlight,
    parbox = false,
    colbacktitle = accent,
    halign title = center,
    boxed title style = {
        enhanced,
        colback = accent,
        colframe = accent,
        top = 0.8mm,
        bottom = 1.4mm,
        overlay = {
            \pic[fill = accent] at (frame.west) {leftcap};
            \pic[fill = accent,xscale=-1] at (frame.east) {leftcap};
            \pic[fill = accent] at (frame.south) {tip};
            \pic[fill = accent] at (frame.north) {tip};
        },
    },
}
\ifdefined\blackwhite
\newtcolorbox{dragonbox}[2][]{
    left = 2em,
    right = 2em,
    top = 2.5em,
    bottom = 1.5em,
    interior code = {
        \draw[line width = 2pt] (frame.north west) -- (frame.north east);
        \draw[line width = 2pt] (frame.south west) -- (frame.south east);
        \pic at (frame.north west) {head};
        \pic at (frame.north east) {head};
        \pic at (frame.south west) {head};
        \pic at (frame.south east) {head};
        \pic[scale=1.25] at (frame.south) {tip};
    },
    colframe = white,
    fuzzy shadow={.5mm}{-.5mm}{-1mm}{.5mm}{black!50!white},
    adjusted title = \uppercase{#2},
    attach boxed title to top center = {yshift=-\tcboxedtitleheight/2},
    boxed title style = {
        top = 1mm,
        bottom = 1.4mm,
        left = 2em,
        right = 2em,
    },
    #1
}
\else
\newtcolorbox{dragonbox}[2][]{
    left = 2em,
    right = 2em,
    top = 2.5em,
    bottom = 1.5em,
    interior code = {
        \draw[line width = 2pt] (frame.north west) -- (frame.north east);
        \draw[line width = 2pt] (frame.south west) -- (frame.south east);
        \pic at (frame.north west) {head};
        \pic at (frame.north east) {head};
        \pic at (frame.south west) {head};
        \pic at (frame.south east) {head};
        \pic[scale=1.25] at (frame.south) {tip};
    },
    opacityfill = 0,
    frame style = {
            fill overzoom image = img/scroll.png,
    },
    fuzzy shadow={.5mm}{-.5mm}{-1mm}{.5mm}{black!50!white},
    adjusted title = \uppercase{#2},
    attach boxed title to top center = {yshift=-\tcboxedtitleheight/2},
    boxed title style = {
        top = 1mm,
        bottom = 1.4mm,
        left = 2em,
        right = 2em,
    },
    #1
}
\fi
\newtcolorbox{demonbox}[2][]{
    left = 2em,
    right = 2em,
    top = 1em,
    bottom = 2em,
    coltext = textlight,
    colback = accent,
    colframe = accent,
    overlay = {
        \pic[fill = accent,yscale=-1] at (frame.north west) {leftspike};
        \pic[fill = accent,scale=-1] at (frame.north east) {leftspike};
        \pic[fill = accent] at (frame.north) {tip};
        \pic[fill = accent] at (frame.south west) {leftspike};
        \pic[fill = accent,xscale=-1] at (frame.south east) {leftspike};
        \pic[fill = accent] at (frame.south) {tip};
        \draw ([xshift=2em,yshift=-.9cm]frame.north west) -- ([xshift=-2em,yshift=-.9cm]frame.north east);
    },
    fuzzy shadow={.5mm}{-.5mm}{-1mm}{.5mm}{black!50!white},
    adjusted title = \uppercase{#2},
    attach boxed title to top,
    boxed title style = {
        overlay = {},
    },
    #1
}
\newtcolorbox{emptybox}[2][]{
    left = -.15cm,
    right = -.15cm,
    leftright skip = 0pt,
    top = .5em,
    bottom = 1em,
    frame hidden,
    interior hidden,
    adjusted title = \uppercase{#2},
    attach boxed title to top,
    #1
}
%%========= HEADINGS =========%%
\RequirePackage[sf,bf,uppercase,explicit]{titlesec}
% \setcounter{secnumdepth}{0}

\newcommand{\partimage}[1]{\def\part@image{\includegraphics[width=17cm,height=24cm,clip]{#1}}}
\partimage{example-image}
\titleformat{\part}{}{}{0pt}{
    \hspace{-6mm}%
    \begin{tikzpicture}
        \node[fill = accent,inner sep = 0pt,minimum width = 17.2cm,minimum height = 24.2cm] (border) at (8.5,12) {\ifdefined\part@image\part@image\fi};
        \draw[color = accent,line width = 2.2mm] (0,0) rectangle (17,24);
        \pic[fill = accent] at (border.south west) {leftspike};
        \pic[fill = accent,yscale=-1] at (border.north west) {leftspike};
        \pic[fill = accent,xscale=-1] at (border.south east) {leftspike};
        \pic[fill = accent,scale=-1] at (border.north east) {leftspike};
        \pic[fill = accent] at (border.south) {tip};
        %
        \node[fill = accent,text = textlight,minimum height = 13.5mm,inner xsep = 1cm,text centered] (header) at ([yshift=-1mm]border.north) {\fontsize{30pt}{30pt}\titlefont\uppercase{#1}};
        \pic[fill = accent,scale=1.5] at (header.west) {leftcap};
        \pic[fill = accent,scale=-1.5] at (header.east) {leftcap};
        \pic[fill = accent,scale=1.5] at (header.south) {tip};
        %
        \node[fill = accent,text = textlight,minimum height = 4.5mm,inner xsep = 1em,text centered] (label) at (header.north) {\normalsize\titlefont PART~\thepart};
        \pic[fill = accent,scale=0.5] at (label.west) {lefttip};
        \pic[fill = accent,scale=-0.5] at (label.east) {lefttip};
        \pic[fill = accent] at (label.north) {tipup};
    \end{tikzpicture}
}
\titlespacing*{\part}{0pt}{-1cm}{-1cm}

% \titleformat{\chapter}[hang]{}{}{0pt}{
%     \hspace{-2.5mm}%
%     \begin{tikzpicture}
%         \pic[fill = accent] at (0,0) {head};
%         \pic[fill = accent] at (17,0) {head};
%         \node[text = accent] (header) at (8.5,0) {\Huge\bfseries\sffamily\uppercase{#1}};
%         \draw[color = accent,line width = 2pt] (0,0) -- (header.west);
%         \draw[color = accent,line width = 2pt] (header.east) -- (17,0);
%     \end{tikzpicture}
% }
\def\thechapterhead{CHAPTER~\thechapter}
\titleformat{\chapter}[hang]{}{}{0pt}{
    \hspace{-2.5mm}%
    \begin{tikzpicture}
        \node[text = accent,minimum height = 2cm] (heading) at (0,0) {\fontsize{34pt}{34pt}\titlefont\uppercase{#1}};
        %
        \node[fill = accent,minimum height = 4.5mm,minimum width = 17cm] (header) at ([yshift = 2mm]heading.north) {};
        \pic[fill = accent,scale=0.5] at (header.west) {leftcap};
        \pic[fill = accent,scale=-0.5] at (header.east) {leftcap};
        \pic[fill = accent] at (header.south) {tip};
        %
        \node[fill = accent,text = textlight,minimum height = 4.5mm,inner xsep = 1em,text centered] (label) at (header.north) {\normalsize\titlefont \thechapterhead};
        \pic[fill = accent,scale=-0.5] at (label.east) {lefttip};
        \pic[fill = accent,scale=0.5] at (label.west) {lefttip};
        \pic[fill = accent] at (label.north) {tipup};
        %
        \node[minimum width = 17cm] (bottom) at (heading.south) {};
        \draw[color = accent,line width = 3pt] (bottom.east) -- (bottom.west);
        \pic[fill = accent] at (bottom.east) {head};
        \pic[fill = accent] at (bottom.west) {head};
        \pic[fill = accent,scale=1.5] at (bottom) {tip};
    \end{tikzpicture}
}
\titlespacing*{\chapter}{0pt}{-1.5cm}{0pt}

\titleformat{\section}{\color{accent}\fontsize{34pt}{34pt}\titlefont\uppercase}{}{0pt}{\hfill~#1~\hfill}
\titlespacing*{\section}{0pt}{0pt}{1em}

\titleformat{\subsection}{\titlefont\large\uppercase}{}{0pt}{#1}
\titlespacing*{\subsection}{0pt}{1em}{0pt}

\titleformat{\subsubsection}{\titlefont\normalsize\uppercase}{}{0pt}{\hfill~#1~\hfill}
\titlespacing*{\subsubsection}{0pt}{1em}{0pt}

\titleformat{\paragraph}[runin]{\titlefont\footnotesize}{}{0pt}{#1~\quad}
\titlespacing*{\paragraph}{0pt}{1em}{0pt}
%%========= HEADERS =========%%
\def\thefooter{\MakeUppercase{\@title}}
\def\ps@plain{
    \def\@evenhead{}
    \let\@oddhead\@evenhead
    \def\@evenfoot{
        \begin{minipage}[b][2cm][c]{17cm}\centering
        \begin{tikzpicture}
            \pic[fill = accent] at (0,1) {upspike};
            \pic[fill = accent] at (0,0) {downspike};
            \node[text = textlight] (page) at (0,0) {\bfseries\sffamily\thepage};
            \node[text = accent] (chapter) at (0,.5) {\small\bfseries\sffamily\thefooter};
        \end{tikzpicture}
        \end{minipage}
    }
    \let\@oddfoot\@evenfoot
}
\def\ps@headings{
    \def\@evenhead{% \color{accent}\hrulefil
        \hspace{-2.5mm}%
        \begin{tikzpicture}
            \draw[color = accent,line width = 3pt] (0,0) -- (17,0);
            \pic[fill = accent] at (0,0) {head};
            \pic[fill = accent,scale=1.5] at (8.5,0) {tip};
            \pic[fill = accent] at (17,0) {head};
        \end{tikzpicture}
    }
    \let\@oddhead\@evenhead
    \def\@evenfoot{
        \begin{minipage}[b][2cm][c]{17cm}\centering
        \begin{tikzpicture}
            \pic[fill = accent] at (0,1) {upspike};
            \pic[fill = accent] at (0,0) {downspike};
            \node[text = textlight] (page) at (0,0) {\large\titlefont\thepage};
            \node[text = accent] (chapter) at (0,.5) {\small\titlefont\thefooter};
        \end{tikzpicture}
        \end{minipage}
    }
    \let\@oddfoot\@evenfoot
}
\def\ps@myheadings{
    \def\@evenhead{}
    \let\@oddhead\@evenhead
    \def\@evenfoot{\footnotesize
        \begin{minipage}[b][2cm][c]{8.5cm}
            \includegraphics[height=2cm]{img/Dragonbane-license-logo-red.png}
        \end{minipage}
        \begin{minipage}[b][2cm][c]{8.5cm}
            \ding{70}~{\titlefont{\scriptsize \@authorkey}:} \@author~(Version \@version)
            
            \ding{70}~{\titlefont{\scriptsize \@creditskey}:} \@credits
        \end{minipage}
    }
    \let\@oddfoot\@evenfoot
}
\ifdefined\onlyonepage
    \pagestyle{myheadings}
\else
    \pagestyle{headings}
\fi