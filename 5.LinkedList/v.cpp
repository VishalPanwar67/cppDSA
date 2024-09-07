State  Input Output
        0 1      
 A      B B    1
 B      A B    0  
 C      B A    1
 D      A B    0
 E      B A    1

 pi1 = {{A},{B,D},{C,E}}

 State  Input Output
        0 1      
 A      B B     1   
 B      C B     0    
 C      B A     1  
 D      C B     0
 E      B A     1
 pi2 ={{A},{B,D},{C,E}};

 pi1=pi2 

State   Input     Output
         0     1     
 {A}    {B,D} {B,D}  1
 {B,D}  {C,E} {B,D}  0     
 {c,E}  {B,D} {A}    1
