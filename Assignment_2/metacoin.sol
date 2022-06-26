pragma solidity >=0.4.25 <0.7.0;


contract MetaCoin {
	mapping (address => uint256) balances;

	event Transfer(address indexed _from, address indexed _to, uint256 _value);

	constructor() public {
		balances[tx.origin] = 100000;
	}

	function sendCoin(address receiver, uint256 amount, address sender) public returns(bool sufficient) {
		if (balances[sender] < amount) return false;
		balances[sender] -= amount;
		balances[receiver] += amount;
		emit Transfer(sender, receiver, amount);
		return true;
	}


	function getBalance(address addr) public view returns(uint256) {
		return balances[addr];
	}
}


contract Loan is MetaCoin {
    mapping (address => uint256) private loans;
     
    event Request(address indexed _from, uint256 P, uint R, uint T, uint256 amt);
    event ResetOwner(address indexed oldOwner, address indexed newOwner);

    address private Owner;

    
    modifier isOwner() {
        require(msg.sender==Owner, "You do not have the Owner Rights");
        _;
    }
    
    constructor() public {
        // Owner = address(0);
        Owner = msg.sender; // 'msg.sender' is sender of current call, contract deployer for a constructor
        emit ResetOwner(address(0), Owner); //Within an Ethereum transaction, the zero-account is just a special case used to indicate that a new contract is being deployed.
    }
    
    // Fill up the following function definitions and also try to justify why some functions are pure and some are view and some are none, in your README.md
    
    function getCompoundInterest(uint256 principle, uint rate, uint time) public pure returns(uint256) {
    	for(uint256 i=0; i<time; i++){
            uint256 p = principle*rate*time;
            p = p/100;
            principle+=p;
        }
        return principle;
    }
    
    function reqLoan(uint256 principle, uint rate, uint time) public returns(bool correct) {
        uint256 toPay = getCompoundInterest(principle, rate, time);
        address requestor = msg.sender;
        loans[requestor] = toPay;

        if(loans[requestor]!=0){return true;}
        else{return false;}
    }
    
    function getOwnerBalance() public view returns(uint256) {
			return getBalance(Owner);
		}
    
    
    function viewDues(address cred) public isOwner view returns(uint256){
        return loans[cred];
    }

    function settleDues(address cred) public isOwner returns(bool done){
        sendCoin(Owner, loans[cred], cred);
        if(sendCoin(Owner, loans[cred], cred)){
            loans[cred] = 0;
        }
        if(loans[cred] == 0){return true;}
        else{return false;}
    }
    
}
