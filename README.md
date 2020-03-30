# Proplang - tool for propositional logics calculations

Formal grammar structure:
```java
<program>           ::=   <exp>','<program> | <exp>
<exp>               ::=   'in'<prop>    |
                          'out'<prop>   |
                          <prop>:=<formulae>
<formulae>          ::=   '('<formulae>^<formulae>')'  |
                          '('<formulae>v<formulae>')'  |
                          '('<formulae>=><formulae>')' |
                          '('<formulae><=><formulae>')'|
                          ~<formulae> | <prop> | '0' | '1' | 'F' | 'T' | 'false' | 'true'
```
