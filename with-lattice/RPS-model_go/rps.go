//author      		    : renata <renatatrintin@gmail.com>
//notes       		    : RPS_model with lattice
//compilation/execution : go run rps.go *seed

package main

import (
	"fmt"
	"math/rand"
	"log"
	"os"
	"strconv"
)

func main() {
	dx := 250  /* grid size      		*/
	dy := 250  /* grid size      		*/
	N  := 1000 /* number of generation	*/
	seed, _ := strconv.ParseInt(os.Args[1], 10, 64)
	rand.Seed(seed)

	phi := make([]int, dx*dy) /* phi: vector that stores which species/empty space is at a given place on the network */
//	phi := make([][]int, dx)
//	for i := 0; i < dx; i++ {
//		phi[i] = make([]int, dy)
//	}
	dst := make([]int, 4)     /* density species time */

/* INITIAL CONDITION - begin  */
	for i := 0; i < dx; i++ {
		for j := 0; j < dy; j++ {
			b := rand.Intn(3)
			phi[j*dx+i] = b+1
		}
	}
	
	f, err := os.Create("dat/data-0.dat")
	if err != nil {
     	log.Fatal(err)
	}
	
	for i := 0; i < dx; i++ {
		for j := 0; j < dy; j++ {
			fmt.Fprint(f, phi[i*dy+j], " ")
		}
		fmt.Fprintln(f, "")
	}
	f.Close()
/* FINAL CONDITION - end  */
	for i := 0; i < dx*dy; i++{
		dst[phi[i]]++
	}

	h, _ := os.OpenFile("dat/dst.dat", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	for i := 1; i < 4; i++ { /* printing of initial species density over time */
		fmt.Fprintf(h, "%e ", float64(dst[i])/float64((dx*dy)))
	}
	fmt.Fprintf(h, "%e\n", float64(dst[0])/float64((dx*dy)))
	defer h.Close()
	
	for t := 0; t < N; t++ {
		gd := 0
		for gd < (dx*dy){
			k := rand.Intn(dx) /* line   */
			l := rand.Intn(dy) /* column */
			ac := k*dy+l
			if phi[ac] != 0 {
				ps := 5
				viz := rand.Intn(4)
				switch viz{
					case 0:
        					ps = k*dy+((l+1)%dy)
					case 1:
        					ps = k*dy+((l-1+dy)%dy)
    					case 2:
        					ps = ((k+1)%dx)*dy+l
    					case 3:
        					ps = ((k-1+dx)%dx)*dy+l
    				}
    				action := rand.Intn(100)
    				if action < 50 { /* mobility */
					temp := phi[ps];
					phi[ps]= phi[ac];
					phi[ac]= temp;
					gd++;
				}else if action < (50+25){ /* predation */
					if phi[ps] != 0 && phi[ac]%3 == phi[ps]-1{ 
						dst[phi[ps]]--;
						dst[0]++;
						phi[ps]= 0;
						gd++;
					}	
				}else if phi[ps] == 0{ /* reproduction */
					phi[ps]= phi[ac];
					dst[phi[ps]]++;
					dst[0]--;
					gd++;
				}
			}
		}
		for i := 1; i < 4; i++ { /* printing of species density over time */
			fmt.Fprintf(h, "%e ", float64(dst[i])/float64((dx*dy)))
		}
		fmt.Fprintf(h, "%e\n", float64(dst[0])/float64((dx*dy)))
		
		if t%100 == 0{ /* printing of snapshots */
			n := t/100;
			name := fmt.Sprintf("dat/data-%d.dat", n+1)
			fmt.Println(name, t)
			g, _ := os.Create(name)
			for i := 0; i < dx; i++ {
				for j := 0; j < dy; j++ {
					fmt.Fprint(g, phi[i*dy+j], " ")
				}
				fmt.Fprintln(g, "")
			}
			g.Close()
		}	
	}	
	fmt.Println("done")
}

