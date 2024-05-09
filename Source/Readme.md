Modules
===============================================
## VClassDemo5_4
5.4.1 release 버전의 VClass 프로토타입 모듈
### MoCapData.cpp
Dollars Mono에서 보내주는 모션캡쳐 데이터와 헤더를 클라이언트로 보내줄 때 사용하는 구조체입니다
> - **TArray<float> OSCFloats** <br>
> 모션캡쳐 데이터가 들어있는 TArray입니다. <br>
> - **TArray<FString> OSCAddress** <br>
> 데이터에 대한 설명이 들어있는 TArray입니다.
### MyGameModeBase
테스트용 게임모드 베이스입니다. PreLogin으로 얻어온 Options데이터를 lastLoginRequestOption변수에 저장하는 기능만 구현되어 있습니다
> - **FString lastLoginRequestOption** <br>
> 마지막으로 로그인한 클라이언트의 Options데이터를 저장하는 변수입니다.
### VClassDollarsClientReceiver
빈 클래스입니다. 후에 Dollars MoCap을 C++로 바꿀때 사용하려고 남겨놨습니다.
### VClassGestureCaptor
현재 모션캡쳐 데이터에서 제스쳐 데이터를 추출하여 로지스틱 회귀 학습에 사용할 데이터로 정제하기 위해 제작한 액터 컴포넌트 클래스입니다.
블루프린트에 상속하여 기능을 구현하므로, C++에서는 파일을 읽고 쓰는 기능만이 구현되어있습니다.
> - **static FString ReadStringToFile(FString FilePath, bool& bOutSuccess, FString& OutinfoMessage)** <br>
> 파일에서 문자열을 읽어오는 함수입니다. <br>
> - **static void WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)** <br>
> 문자열을 파일에 저장하는 함수입니다. <br>
> - **static void AddStringToFile(FString FilePath, FString String) <br>
> 파일에 문자열을 추가하는 함수입니다. <br>
### VClassGestureRecognitor
현재 모션캡쳐 데이터에서 제스쳐 데이터를 추출하여 어떤 제스쳐인지 예측하는 기능을 수행하는 액터 컴포넌트입니다
> - **Array<float> InputData** <br>
> 블루 프린트에서 전처리된 제스쳐 데이터를 저장하는 실수형 TArray입니다. 제스쳐 데이터는 길이가 16이므로 이 리스트의 길이 역시 16을 상정합니다. <br>
> - **FString Predict()** <br>
> InputData를 활용해 실질적인 제스쳐 인식을 담당하는 로지스틱 모델 함수입니다. 반환형은 FString 배열 categories의 요소중 하나가 됩니다. <br>
> - **FString CurrentGesture** <br>
> 현재 제스쳐를 저장하고 있는 변수입니다. TickComponent에서 제스쳐의 예측값이 바뀔 때 마다 해당값으로 업데이트됩니다. <br>
> - **FOnGestureChangedDelegate OnGestureChanged** <br>
> TickComponent에서 제스쳐의 예측값이 바뀌었을 때, CurrentGesture를 업데이트 하기 전에 호출되는 Dynamic Multicast TwoParams 대리자입니다. 인자로는 현재 제스쳐와 바뀐 제스쳐의 FString을 받습니다. <br>
> - **float[16][n] weights** <br>
> 제스쳐 인식 로지스틱 모델이 사용할 하드 코딩된 가중치 2D 행렬입니다. 2D의 길이는 16으로 이는 제스쳐 데이터의 길이를 의미하고, 1D의 길이는 n으로 이는 categories의 길이, 즉, 모델이 분류할 수 있는 제스쳐의 종류의 개수를 의미합니다. 예제 프로젝트에선 5로 지정되어 있습니다. <br>
> - **TArray<FString> categories** <br>
> 로지스틱 모델이 분류할 제스쳐의 종류를 담는 FString 리스트입니다. 예제 프로젝트에선 “Thumbs_up”,“open_hands”,“pointing”,“rock”,“v_sign”의 5개의 견본 제스쳐가 입력되어 있습니다. <br>
> - **float** MatrixM2D(float** A, int* A_Shape, float** B, int* B_Shape, bool& bOutSuccessful)** <br>
> 로지스틱 모델에서 사용할 2차원 행렬곱 연산을 수행하는 함수입니다. 파이썬의 “A@B” 연산과 동일한 기능을 수행하며, A_Shape과 B_Shape은 각각 A,B 행렬의 2차원 크기를 길이 2의 정수배열로 받습니다. 이때 넘겨받은 정수 배열은 연산 종료후 할당된 메모리를 해제합니다. bOutSuccessful은 행렬곱 연산이 제대로 수행되었는지 결과를 반환합니다. 해당 함수에선 두 행렬의 크기가 행렬곱 연산을 수행할 수 없을 경우에만 false를 반환합니다. <br>
### VClassStateMachine
현재 강연자의 상태 전반을 관리하고, 기능제어 로직을 담당하는 액터 클래스입니다.
> - **enum class VClassState : uint8** <br>
> 강연자의 상태를 나타낼 enum 클래스입니다. 예제 프로젝트에선 “Plain”과 “Testing”의 두가지 상태가 작성되어 있습니다. <br>
> - **VClassState CurrentState** <br>
> 현재 강연자의 상태를 나타내는 변수입니다. <br>
> - **void OnGestureChangedEvent (const FString& startGesture, const FString& endGesture)** <br>
> VClassRecognitor의 OnGestureChanged 대리자에 바인딩할 BlueprintInplementableEvent입니다. 해당 함수는 블루프린트에서 이벤트로서 구현합니다. <br>
> - **void SetVClassState(VClassState new_state)** <br>
> new_state로 강연자의 상태를 업데이트하는 함수입니다. <br>
> - **void InitVClassStateMachine()** <br>
> 이 스테이트 머신을 초기화 하는 함수입니다. 이 함수에서 로컬 플레이어 컨트롤러의 VClassRecognitor의 OnGestureChanged 대리자에 OnGestureChangedEvent를 바인딩하며, Client-Side의 BeginPlay에서 호출합니다. <br>
### VLChair
클라이언트가 입장후 착석할 위치를 담당하는 액터 클래스입니다.
> - **UStaticMeshComponent\* Body** <br>
> 의자의 메쉬를 저장하는 UStaticMeshComponent입니다. <br>
> - **USceneComponent\* SitTransform** <br>
> 클라이언트가 착석할때 고정될 위치를 담당하는 USceneComponent입니다. <br>
> - **FString name** <br>
> 이 의자의 이름입니다. 좌석번호로 사용하려고 추가했습니다. <br>
> - **FTransform GetSittingTransform()** <br>
> SitTransform의 트랜스폼 구조체를 반환하는 BlueprintCallable함수입니다.
