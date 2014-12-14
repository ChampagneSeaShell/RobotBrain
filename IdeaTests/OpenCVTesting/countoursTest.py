import numpy as np
import cv2

#calibration variables
startingPositon
startingDirection
vec2 OriginalDesiredDirection
float DistanceOfGoal;
float ExtraDistancel

DesiredEndPosition = SetNewEndPoint(OriginalDesiredDirection, DistanceOfGoal);





shapeToStayIn;
#----------getting the imediate collisions ------------
#image = cv2.VideoCapture(0)
image = cv2.OpenImage("/home/chris/Pictures/TestImages/BirdsEye.jpg2");

startColour = { 167, 166, 174};
endColour = { 218, 205, 189 };
theFloor = cv2.inRange(image, startColour, endColour);
countours = cv2.findContours(theFloor, mode, method);
shapeToStayIn = countours;
#--------------------------

#CreateGrid



RaceOnLoop()
{
    if(HasCrossedLine())
    {
        End; 
    }
    if(HasReachedEndPoint() && !HasCrossedLine())
    {
        DiffFromDesiredDirection = OriginalDesiredDirection - CurrentDirection;        
        SetNewEndPoint(DiffFromDesiredDirection, ExtraDistance);        
    }
    RecreateAStarGrid();
    WorkOutPositionOnGrid();
    SetNewEndPointToAStarTarget();
    
}


CentreOfCircle()
{
    if(HasReachedCentre())
    {
        End;
    }
    if(KnowsCentre())
    {
        MoveTowardsEndPoint();
    }
    else
    {
        if(!FoundArcLine)
        {
            MoveForward()
            ScanForArc();            
        }
        else #Found arc, not processed
        {
            KnowsCentre = WorkOutCentreFromArc();
        }
    }
}

#this would work best if using behavours
#the robot would "pursue" an end point
#the end point would "pursue" something directly in front of the robot BUT 
#would colide with something slightly bigger thencircle
GoRoundCircle 
{
    if(!FoundLine)
    {
        MoveForward()
        ScanForArc();    
    }
    else
    {
        if(DistanceFromArc > allowedFarDistance)
        {
            MoveTowardsArc;
        }
        else if(DistanceFromArc < allowedNearDistance)
        {
            MoveAwayFromArc;
        }
    }
 
 }





#----------IGNOR-----get goal intellegently-------------------------
#get rid of floor
image = cv2.OpenImage("/home/chris/Pictures/TestImages/FirstPosition.jpg
theFloor = cv2.inRange(image, startColour, endColour);
noFloor = cv2.subtract(theFloor, image);
horizonEye = cropImage(theFloor, bottom+1); #this would crop the image to a 1D texture 
furthestPoint = depthTest(horizonEye); #find the part in the image furthest away.
goal = translateToBirdseyePlane(furthestPoint);
set(furthestPoint);









#cv2.findContours(
cv2.

cap.release()
cv2.destroyAllWindows()
