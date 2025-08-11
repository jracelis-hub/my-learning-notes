# CSS ( Cascade Style Sheet)

# Introduction 

CSS or _Cascade Style Sheet_ is used to style and change the appearance of HTML files. 

There are 3 types of ways to add CSS to a HTML file:

1. Inline - using style inside a HTML element `< h1 style="">`
2. Internal - adding style in `<head>style="item"</head>` 
3. External `<link rel="stylesheet" href="relative_path">

The format for external is the following:
```css
/* Each Selector is enclosed in { }*/
selector {
	property1: value1;
	property2: value2;
}
```

## Flexbox


```css
body {
	
	display: flex;	

	flex-direction: row; /* This is set by default */ 
	flex-direction: column;

	/* Justify Is for the main axis */
	justify-content: flex-start; /* This is set by default */
	justify-content: flex-end; /* At the end of main axis */
	justify-content: center; /* At the center of main axis */
	justify-content: flex-start; /* This is set by default */
	align-content: space-between;
	align-content: space-evenly;


	/* Justify Is For The Cross axis */
	align-items: flex-start; /* At the top */
	align-items: flex-end; /* At the bottom*/
	align-items: center; /* In the Middle*/
	align-items: baseline; /* The text is aligned */

	flex-wrap: nowrap; /* Default */
	flex-wrap: wrap;

	/* Only works if wrap is enabled */
	/* Used for cross axis */
	align-content: flex-start;
	align-content: flex-end;
	align-content: center;
	align-content: space-between;
	align-content: space-evenly;

	/* To set space*/
	gap: ;

	flex-grow: 0;
	flex-shrink: 0; /* Item will never shrink */
	flex-basis: 0; /* To overwrite item */
	flex: ;zz

	/* To overwrite align-items*/
	align-self: ;

	/* To change the order */
	order: ;
}
```

```
  justify-content: flex-start;                 
  -------------------------------------------------
  |        |        |        |                    |                                              
  |        |        |        |                    |                                             
  |---------------------------                    |
  | flex-direction: row;|                         |
  |                     |                         |
  |                     |       main axis         |
  |---------------------------------------------------> 
  |                     |                         |
  |                     | cross axis              |
  |                     |                         |
  |                     |                         |
  |                    \|/                        |
  -------------------------------------------------

   justify-content: center;                                              
  -------------------------------------------------
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |           ------------------------            |
  |           |       |       |      |            |
  |           |       |       |      |            |
  |           ------------------------            |
  |                                               |
  |                                               |
  |                                               |
  -------------------------------------------------


   justify-content: flex-end;                    
  -------------------------------------------------
  |                       |       |       |       |
  |                       |       |       |       |                                                
  |                       ------------------------|
  |                                               |
  |                                               |
  |                                               |
  |---------------------------------------------------> 
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  -------------------------------------------------

   justify-content: space-between;               
  -------------------------------------------------
  |       |           |      |           |        |
  |       |           |      |           |        |
  |--------           --------           ---------|
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------

   justify-content: space-evenly;               
  -------------------------------------------------
  |       |      |     |      |     |      |      |
  |       |      |     |      |     |      |      |
  |       --------     --------     --------      |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------

  -------------------------------------------------
  |        |              |                       |                                              
  |        |              | flex-direction: column|                                            
  |---------              |                       |
  |        |              |                       |
  |        |    main axis |                       |
  |-----------------------|---------------------->|      
  |        |              |     cross axis        |
  |        |              |                       |
  |---------              |                       |
  |                       |                       |                                                
  |                       |                       |                                                
  |                      \|/                      |                                                
  -------------------------------------------------
```


## Template

```
  -------------------------------------------------
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  | justify-cotent: flex-end;                     |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------
```
