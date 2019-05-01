# -*- coding: utf-8 -*-
import pygame, sys, time
import pygame.locals

from node_class import Node

class Visu:
    TILESIZE = 80
    WINDOWWIDTH = 840
    WINDOWHEIGHT = 680
    BLANK = None

    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    BRIGHTBLUE = (0, 50, 255)
    DARKTURQUOISE = (3, 54, 73)
    GREEN = (0, 204, 0)

    BGCOLOR = DARKTURQUOISE
    TILECOLOR = GREEN
    TEXTCOLOR = WHITE
    BORDERCOLOR = BRIGHTBLUE
    BASICFONTSIZE = 20

    BUTTONCOLOR = WHITE
    BUTTONTEXTCOLOR = BLACK
    MESSAGECOLOR = WHITE

    def __init__(self, algo):
        self.BOARDWIDTH, self.BOARDHEIGHT, self.XMARGIN, self.YMARGIN = self.set_format()
        pygame.init()
        self.DISPLAYSURF = pygame.display.set_mode((Visu.WINDOWWIDTH, Visu.WINDOWHEIGHT))
        pygame.display.set_caption('Slide Puzzle')
        self.BASICFONT = pygame.font.Font('freesansbold.ttf', Visu.BASICFONTSIZE)
        self.algo = algo

        self.PREV_SURF, self.PREV_RECT = self.makeText(' < ', Visu.TEXTCOLOR, Visu.BORDERCOLOR,
                                                       self.XMARGIN + Visu.TILESIZE * 1 / 4, Visu.WINDOWHEIGHT - self.YMARGIN * 3 / 4)

        self.PREV_SURFTXT, self.PREV_RECTTXT = self.makeText('Prev', Visu.TEXTCOLOR, Visu.BGCOLOR,
                                                       self.XMARGIN + Visu.TILESIZE * 1 / 4 - 10, Visu.WINDOWHEIGHT - self.YMARGIN * 0.6)

        self.NEXT_SURF, self.NEXT_RECT = self.makeText(' > ', Visu.TEXTCOLOR, Visu.BORDERCOLOR,
                                                       Visu.WINDOWWIDTH / 2 + Visu.TILESIZE, Visu.WINDOWHEIGHT - self.YMARGIN * 3 / 4)

        self.NEXT_SURFTXT, self.NEXT_RECTTXT = self.makeText('Next', Visu.TEXTCOLOR, Visu.BGCOLOR,
                                                             Visu.WINDOWWIDTH / 2 + Visu.TILESIZE - 10, Visu.WINDOWHEIGHT - self.YMARGIN * 0.6)

        self.PLAY_SURF, self.PLAY_RECT = self.makeText("Play ", Visu.TEXTCOLOR, Visu.BORDERCOLOR,
                                                       Visu.WINDOWWIDTH / 2 - 15, Visu.WINDOWHEIGHT - self.YMARGIN * 3 / 4)


    def set_format(self):
        bw = Node.size
        bh = Node.size
        xm = int((Visu.WINDOWWIDTH - Visu.TILESIZE * bw) / 2)
        ym = int((Visu.WINDOWHEIGHT - Visu.TILESIZE * bh) / 2)
        return bw, bh, xm, ym

    def makeText(self, text, color, bgcolor, top, left):
        """create the Surface and Rect objects for some text."""
        textsurf = self.BASICFONT.render(text, True, color, bgcolor)
        textrect = textsurf.get_rect()
        textrect.topleft = (top, left)
        return (textsurf, textrect)

    def build_board_struct(self, puzzle):
        """Returns a board structure: a list of list representing columns"""
        board = []
        c = 0
        while c < Node.size:
            l = c
            list_col = []
            while l < Node.size ** 2:
                list_col.append(puzzle[l])
                l += Node.size
            board.append(list_col)
            c += 1
        return board

    def getLeftTopOfTile(self, tileX, tileY):
        left = self.XMARGIN + (tileX * Visu.TILESIZE) + (tileX - 1)
        top = self.YMARGIN + (tileY * Visu.TILESIZE) + (tileY - 1)
        return left, top

    def drawTile(self, tilex, tiley, number, adjx=0, adjy=0):
        """draw a tile at board coordinates tilex and tiley, optionally a few pixels over
        (determined by adjx and adjy)"""
        left, top = self.getLeftTopOfTile(tilex, tiley)
        pygame.draw.rect(self.DISPLAYSURF, Visu.TILECOLOR, (left + adjx, top + adjy, Visu.TILESIZE, Visu.TILESIZE))
        text_surf = self.BASICFONT.render(str(number), True, Visu.TEXTCOLOR)
        text_rect = text_surf.get_rect()
        text_rect.center = left + int(Visu.TILESIZE / 2) + adjx, top + int(Visu.TILESIZE / 2) + adjy
        self.DISPLAYSURF.blit(text_surf, text_rect)

    def drawBoard(self, board, message):
        """Handles drawing the entire board and all of its tiles to the DISPLAYSURF display Surface object"""
        self.DISPLAYSURF.fill(Visu.BGCOLOR)
        if message:
            text_surf, text_rect = self.makeText(message, Visu.MESSAGECOLOR, Visu.BGCOLOR, 5, 5)
            self.DISPLAYSURF.blit(text_surf, text_rect)
        for tilex in range(len(board)):
            for tiley in range(len(board[0])):
                if board[tilex][tiley]:
                    self.drawTile(tilex, tiley, board[tilex][tiley])
        left, top = self.getLeftTopOfTile(0, 0)
        width = self.BOARDWIDTH * Visu.TILESIZE
        height = self.BOARDHEIGHT * Visu.TILESIZE
        pygame.draw.rect(self.DISPLAYSURF, Visu.BORDERCOLOR, (left - 5, top - 5, width +
                                                    11, height + 11), 4)
        self.DISPLAYSURF.blit(self.PREV_SURF, self.PREV_RECT)
        self.DISPLAYSURF.blit(self.NEXT_SURF, self.NEXT_RECT)
        self.DISPLAYSURF.blit(self.PREV_SURFTXT, self.PREV_RECTTXT)
        self.DISPLAYSURF.blit(self.NEXT_SURFTXT, self.NEXT_RECTTXT)
        self.DISPLAYSURF.blit(self.PLAY_SURF, self.PLAY_RECT)

    def getSpotClicked(self, board, x, y):
        # from the x & y pixel coordinates, get the x & y board coordinates
        for tileX in range(len(board)):
            for tileY in range(len(board[0])):
                left, top = self.getLeftTopOfTile(tileX, tileY)
                tileRect = pygame.Rect(left, top, Visu.TILESIZE, Visu.TILESIZE)
                if tileRect.collidepoint(x, y):
                    return (tileX, tileY)
        return (None, None)

    def update_play_button(self, msg):
        self.PLAY_SURF, self.PLAY_RECT = self.makeText(msg, Visu.TEXTCOLOR, Visu.BORDERCOLOR,
                                                       Visu.WINDOWWIDTH / 2 - 15,
                                                       Visu.WINDOWHEIGHT - self.YMARGIN * 3 / 4)

    def play(self):
        i = 0
        play = 0
        while True:
            msg = ''
            current_board = self.build_board_struct(self.algo.path[i].grid)
            if i == len(self.algo.path):
                msg = 'Solved!'
            self.drawBoard(current_board, msg)
            if play == 1:
                time.sleep(0.8)
                if i < len(self.algo.path) - 1 and not pygame.mouse.get_pressed()[0]:
                    i += 1
            for event in pygame.event.get():
                if event.type == pygame.locals.QUIT:
                    pygame.quit()
                    sys.exit()
                elif event.type == pygame.locals.MOUSEBUTTONUP:
                    spotx, spoty = self.getSpotClicked(current_board, event.pos[0], event.pos[1])
                    if (spotx, spoty) == (None, None):
                        # check if the user clicked on an option button
                        if self.PREV_RECT.collidepoint(event.pos) and not play:
                            if i:
                                i -= 1
                        elif self.NEXT_RECT.collidepoint(event.pos) and not play:
                            if i < len(self.algo.path) - 1:
                                i += 1
                        elif self.PLAY_RECT.collidepoint(event.pos):
                            if not play:
                                play = 1
                                self.update_play_button('Pause')
                            else:
                                play = 0
                                self.update_play_button('Play ')

            pygame.display.update()
